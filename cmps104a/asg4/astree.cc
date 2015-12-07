#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <bitset>

#include "astree.h"
#include "stringset.h"
#include "lyutils.h"
#include "symtable.h" 

symbol_table *glob_Table;
symbol_table *temp_Table;
symbol *temp_sym;
vector<symbol_table*> symbol_stack;
size_t block_nr = 0;
size_t next_block = 1;
size_t depth = 0;
size_t A = 0;       //array variable
extern FILE *symout;

astree* new_astree (int symbol, int filenr, int linenr,
                    int offset, const char* lexinfo) {
   astree* tree = new astree();
   tree->symbol = symbol;
   tree->filenr = filenr;
   tree->linenr = linenr;
   tree->offset = offset;
   tree->lexinfo = intern_stringset (lexinfo);
   
   //pointer to structure table node, initialized to NULL
   tree->block_nr = 0;
   for(int i=0; i<ATTR_bitset_size; i++){
      tree->attributes[i] = false;
   }
   tree = checkATTR(tree);
   DEBUGF ('f', "astree %p->{%d:%d.%d: %s: \"%s\"}\n",
           tree, tree->filenr, tree->linenr, tree->offset,
           get_yytname (tree->symbol), tree->lexinfo->c_str());  
   return tree;
}

static const char *get_yytname_noT (int symbol) {
   const char *tname = get_yytname(symbol);
   if (strstr (tname, "TOK_") == tname) tname += 4;
   return tname;
}

astree* checkATTR(astree* tree) {     // 1   vvv   
   //const char* attr = tree->lexinfo->c_str();
   const char* attr = get_yytname_noT(tree->symbol);
   if(strcmp(attr, "void") == 0) tree->attributes[0] = true;
   if(strcmp(attr, "bool") == 0) tree->attributes[1] = true;
   if(strcmp(attr, "char") == 0) tree->attributes[2] = true;
   if(strcmp(attr, "INT") == 0) tree->attributes[3] = true;
   if(strcmp(attr, "null") == 0) tree->attributes[4] = true;
   if(strcmp(attr, "STRING") == 0) tree->attributes[5] = true;
   if(strcmp(attr, "STRUCT") == 0){
      tree->attributes[6] = true;
   }
   if(strcmp(attr, "TYPEID") == 0) tree->attributes[7] = true;
   if(strcmp(attr, "array") == 0) tree->attributes[8] = true;
   if(strcmp(attr, "FUNCTION") == 0) tree->attributes[9] = true;
   if(strcmp(attr, "variable") == 0) tree->attributes[10] = true;
   if(strcmp(attr, "VARDECL") == 0) tree->attributes[10] = true;
   if(strcmp(attr, "DECLID") == 0) tree->attributes[10] = true;
   if(strcmp(attr, "FIELD") == 0) tree->attributes[11] = true;
   if(strcmp(attr, "lval") == 0) tree->attributes[13]= true;
   if(tree->attributes[10]) tree->attributes[12]= true;
   if(strcmp(attr, "PARAMLIST") == 0) tree->attributes[13] = true;
   if(strcmp(attr, "const") == 0) tree->attributes[14] = true;
   if(strcmp(attr, "STRINGCON") == 0) tree->attributes[14]= true;
   if(strcmp(attr, "INTCON") == 0) tree->attributes[14]= true;
   if(strcmp(attr, "CHARCON") == 0) tree->attributes[14] = true;
   if(strcmp(attr, "vreg") == 0) tree->attributes[15] = true;
   if(strcmp(attr, "vaddr") == 0) tree->attributes[16] = true;
   return tree;
}

attr_bitset copy_ATTR(attr_bitset root, attr_bitset child){
   for(int i=0; i<ATTR_bitset_size; i++){  //print true ATTR
      if (root[i]) {
         child[i] = true;
      }
   }
   return child;
}

astree* adopt1 (astree* root, astree* child) {
   root = checkATTR(root);
   child = checkATTR(child);
   child->attributes = copy_ATTR(root->attributes, child->attributes);
   root->children.push_back (child);
   DEBUGF ('a', "%p (%s) adopting %p (%s)\n",
           root, root->lexinfo->c_str(),
           child, child->lexinfo->c_str());
   return root;
}

astree* adopt2 (astree* root, astree* left, astree* right) {
   adopt1 (root, left);
   adopt1 (root, right);
   return root;
}

astree* adopt3 (astree* root, astree* left, astree* middle, 
                                             astree* right) {
   adopt1 (root, left);
   adopt1 (root, middle);
   adopt1 (root, right);
   return root;
}

astree* stealkids (astree* root, astree* origin) {
   for (size_t child = 0; child < origin->children.size(); ++child) {
      adopt1(root, origin->children[child]);
   }
   return root;
}

astree* adoptsym (astree* root, int symbol) {
   root->symbol = symbol;
   return root;
}

astree* adopt1sym (astree* root, astree* child, int symbol) {
   root = adopt1 (root, child);
   root->symbol = symbol;
   return root;
}

astree* adopt2sym (astree* root, astree* left, astree* right, 
                                                int symbol) {
   adopt2 (root, left, right);
   root->symbol = symbol;
   return root;
}

void dump_attr(FILE* outfile, astree* node){
   if (node->attributes[ATTR_field]) fprintf (outfile, "field ");
   for(int i=0; i<ATTR_bitset_size; i++){  //print true ATTR
      if (node->attributes[i]) {
         switch (i) {
            case ATTR_void :{ fprintf (outfile, "void "); break;}
            case ATTR_bool :{ fprintf (outfile, "bool "); break;}
            case ATTR_char :{ fprintf (outfile, "char "); break;}
            case ATTR_int :{ fprintf (outfile, "int "); break;}
            case ATTR_null :{ fprintf (outfile, "null "); break;}
            case ATTR_string :{ fprintf (outfile, "string "); break;}
            case ATTR_struct :{ 
               fprintf (outfile, "struct "); 
               fprintf (outfile, "\"typeid\" ");
               break;}
            case ATTR_typeid :{ //fprintf (outfile, "\"typeid\" "); 
               fprintf (outfile, "struct "); 
               fprintf (outfile, "\"%s\" ", node->lexinfo->c_str());
               break; }
            case ATTR_array :{ fprintf (outfile, "array "); break;}
            case ATTR_function :{ fprintf (outfile, "function "); 
               break;}
            case ATTR_variable :{ fprintf (outfile, "variable "); 
               break;}
            case ATTR_field :{ break;}
            case ATTR_lval :{ fprintf (outfile, "lval "); break;}
            case ATTR_param :{ fprintf (outfile, "param "); break;}
            case ATTR_const :{ fprintf (outfile, "const "); break;}
            case ATTR_vreg :{ fprintf (outfile, "vreg "); break;}
            case ATTR_vaddr :{ fprintf (outfile, "vaddr "); break;}
            default:
               break;
         }
      }
   }
}

static void dump_node (FILE* outfile, astree* node) {
   const char *tname = get_yytname (node->symbol);
   if (strstr (tname, "TOK_") == tname) tname += 4;
   fprintf (outfile, "%s \"%s\" (%ld.%ld.%ld) {%ld} ", tname, 
   //fprintf (outfile, "%s \"%s\" (%ld.%ld.%ld) {%ld} (0.0.0)", tname, 
            node->lexinfo->c_str(), node->filenr, node->linenr, 
            node->offset, node->block_nr);
   dump_attr(outfile, node);
   bool need_space = false;
   for (size_t child = 0; child < node->children.size();
        ++child) {
      if (need_space) fprintf (outfile, " ");
      need_space = true;
   }
}

static void dump_astree_rec (FILE* outfile, astree* root, int depth) {
   if (root == NULL) return;
   for (int p=0; p<(depth); p++) {
      fprintf (outfile, "%s", "| ");
   }
   dump_node (outfile, root);
   fprintf (outfile, "\n");
   for (size_t child = 0; child < root->children.size(); ++child) {
      dump_astree_rec (outfile, root->children[child], depth + 1);
   }
   return;

}

void dump_astree (FILE* outfile, astree* root) {
   dump_astree_rec (outfile, root, 0);
   fflush (NULL);
}

void free_ast (astree* root) {
   while (not root->children.empty()) {
      astree* child = root->children.back();
      root->children.pop_back();
      free_ast (child);
   }
   DEBUGF ('f', "free [%p]-> %d:%d.%d: %s: \"%s\")\n",
           root, root->filenr, root->linenr, root->offset,
           get_yytname (root->symbol), root->lexinfo->c_str());
   delete root;
}

void free_ast2 (astree* tree1, astree* tree2) {
   free_ast (tree1);
   free_ast (tree2);
}

void free_ast3 (astree* tree1, astree* tree2, astree* tree3) {
   free_ast (tree1);
   free_ast (tree2);
   free_ast (tree3);
}

void yyprint (FILE* outfile, unsigned short toknum, astree* yyvaluep) {
   if (is_defined_token (toknum)) {
      dump_node (outfile, yyvaluep);
   }else {
      fprintf (outfile, "%s(%d)\n",
               get_yytname (toknum), toknum);
   }
   fflush (NULL);
}

int checkLex(const char* lexinfo) {     // 1   vvv
   int lexNum = 0;
   
   if(strcmp(lexinfo, "STRUCT") == 0) lexNum = 1;
   if(strcmp(lexinfo, "DECLID") == 0) lexNum = 2;
   if(strcmp(lexinfo, "FUNCTION") == 0) lexNum = 3;
   if(strcmp(lexinfo, "VARDECL") == 0) lexNum = 4;
   if(strcmp(lexinfo, "BLOCK") == 0) lexNum = 5;
   if(strcmp(lexinfo, "WHILE") == 0) lexNum = 6;
   if(strcmp(lexinfo, "IF") == 0) lexNum = 7;
   if(strcmp(lexinfo, "ELSE") == 0) lexNum = 8;
   if(strcmp(lexinfo, "BINOP") == 0) lexNum = 9;
   if(strcmp(lexinfo, "UNOP") == 0) lexNum = 10;
   if(strcmp(lexinfo, "VARIABLE") == 0) lexNum = 11;
   if(strcmp(lexinfo, "NEW") == 0) lexNum = 12;
   if(strcmp(lexinfo, "CALL") == 0) lexNum = 13;
   if(strcmp(lexinfo, "IDENT") == 0) lexNum = 14;
   if(strcmp(lexinfo, "DECLID") == 0) lexNum = 15;
   if(strcmp(lexinfo, "PROTOTYPE") == 0) lexNum = 16;
   if(strcmp(lexinfo, "PARAMLIST") == 0) lexNum = 17;
   if(strcmp(lexinfo, "IFELSE") == 0) lexNum = 18;
   if(strcmp(lexinfo, "RETURN") == 0) lexNum = 19;
   if(strcmp(lexinfo, "TYPEID") == 0) lexNum = 20;
   return lexNum;
}
 
static bool type_NULL (string type){
   string null_s = "null";
   return (strcmp(type.c_str(), null_s.c_str()) == 0) ;
}

static bool type_Int (string type){
   string int_s = "int";
   return (strcmp(type.c_str(), int_s.c_str()) == 0);
}

static bool type_Bool (string type){
   string bool_s = "bool";
   return (strcmp(type.c_str(), bool_s.c_str()) == 0);
}

static bool type_Char (string type){
   string char_s = "char";
   return (strcmp(type.c_str(), char_s.c_str()) == 0) ;
}

/*static bool type_String (string type){
   string string_s = "string";
   return (strcmp(type.c_str(), string_s.c_str()) == 0) ;
}*/

static bool sameType (string typeA, string typeB){
   if(type_NULL(typeA) || type_NULL(typeB)){
      return true;
   }else{
      return (typeA == typeB);
   }
}

static bool type_Primative (string type){
   return type_Int(type) || type_Char(type) || type_Bool(type); 
}

static void type_err(astree* root, string A, string B){
   errprintf("checkType Error. Invalid types %s, %s at (%d,%d,%d).\n",
            A.c_str(), B.c_str()), root->children[0]->filenr, 
            root->children[0]->linenr, root->children[0]->offset; 
}

string checkType(astree* root){  
   if (root == NULL) return "";
   string typeStr = "";
   if(root->children.size() == 0){
      switch(root->symbol){  
         case TOK_VOID:{ typeStr = root->lexinfo->c_str(); 
            root->attributes[ATTR_void] = true; break; }
         case TOK_BOOL:{ typeStr = root->lexinfo->c_str(); 
            root->attributes[ATTR_bool] = true; break; }
         case TOK_CHAR:{ typeStr = root->lexinfo->c_str(); 
            root->attributes[ATTR_char] = true; break; }
         case TOK_INT:{ typeStr = root->lexinfo->c_str(); 
            root->attributes[ATTR_int] = true; break; }
         case TOK_NULL:{ typeStr = root->lexinfo->c_str(); 
            root->attributes[ATTR_null] = true; break; }
         case TOK_STRING:{ typeStr = root->lexinfo->c_str(); 
            root->attributes[ATTR_string] = true; break; }
         case TOK_INTCON:{ typeStr = "int"; 
            root->attributes[ATTR_const] = true; 
            root->attributes[ATTR_int] = true; break; }
         case TOK_CHARCON:{ typeStr = "char"; 
            root->attributes[ATTR_const] = true; 
            root->attributes[ATTR_char] = true; break; }
         case TOK_STRINGCON:{ typeStr = "string"; 
            root->attributes[ATTR_const] = true; 
            root->attributes[ATTR_string] = true; break; }
         /*case 'false':{ typeStr = "bool"; 
            root->attributes[ATTR_bool] = true;
            root->attributes[ATTR_const] = true; break; }
         case 'true':{ typeStr = "bool"; 
            root->attributes[ATTR_bool] = true;
            root->attributes[ATTR_const] = true; break; }
         case 'null':{ typeStr = "null"; 
            root->attributes[ATTR_null] = true;
            root->attributes[ATTR_const] = true; break; }*/
         case TOK_TYPEID:{ root->attributes[ATTR_typeid] = true;
            break; } 
         case TOK_FIELD:{ root->attributes[ATTR_field] = true;
            break; } 

         default:{ typeStr = ""; 
            break; }
      }
   }else{
      string typeA = "";
      string typeB = "";
      switch(checkLex(root->lexinfo->c_str())){
         case 1:{ root->attributes[ATTR_struct] = true; 
            break; } //struct 
         case 2:{  //declid 
            typeA = checkType(root->children[0]->children[0]);
            typeB = checkType(root->children[0]->children[1]);
            if(typeA != "" && typeB != ""){
               if(sameType(typeA,typeB)){
                  return "";
               }else type_err(root, typeA, typeB);
            }else {
               errprintf ("Error.  Invalid type at (%d,%d,%d).\n", 
                        root->filenr, root->linenr, root->offset); }
            break;
         }
         case 3:{ break; } //normal declaration
         case 4:{ root->attributes[ATTR_function] = true; 
            break; } //function declaration
         case 5:{ break; } //block 
         case 6:{  
         
         
             break; } //while 
         case 7:{ break; } //if 
         case 8:{ break; }//else block
         case 9:{ break; //binop 
            typeA = checkType(root->children[0]->children[0]);
            typeB = checkType(root->children[0]->children[1]);
            if(typeA != "" && typeB != ""){
               switch(root->children[0]->symbol){
                  case '=': 
                  case TOK_EQ:{
                     if(sameType(typeA,typeB)){
                        return typeA;
                     }else type_err(root, typeA, typeB);
                     break;
                  }
                  case TOK_NE:{
                     if(sameType(typeA,typeB)){
                        return typeA;
                     }else type_err(root, typeA, typeB);
                     break;
                  }
                  case TOK_LT:{
                     if(sameType(typeA,typeB)){
                        if(type_NULL(typeA) || type_NULL(typeB)){
                           if(type_NULL(typeA)){
                              if(type_Primative(typeB)){
                                 return typeB;
                              }
                           }
                        }else{
                           if(type_Primative(typeA)){
                              return typeA;
                           }
                        }
                     }else type_err(root, typeA, typeB);
                     break;
                  }
                  case TOK_LE:{
                     if(sameType(typeA,typeB)){
                        if(type_NULL(typeA) || type_NULL(typeB)){
                           if(type_NULL(typeA)){
                              if(type_Primative(typeB)){
                                 return typeB;
                              }
                           }
                        }else{
                           if(type_Primative(typeA)){
                              return typeA;
                           }
                        }
                     }else type_err(root, typeA, typeB);
                     break;
                  }
                  case TOK_GT:{
                     if(sameType(typeA,typeB)){
                        if(type_NULL(typeA) || type_NULL(typeB)){
                           if(type_NULL(typeA)){
                              if(type_Primative(typeB)){
                                 return typeB;
                              }
                           }
                        }else{
                           if(type_Primative(typeA)){
                              return typeA;
                           }
                        }
                     }else type_err(root, typeA, typeB);
                     break;
                  }
                  case TOK_GE:{
                     if(sameType(typeA,typeB)){
                        if(type_NULL(typeA) || type_NULL(typeB)){
                           if(type_NULL(typeA)){
                              if(type_Primative(typeB)){
                                 return typeB;
                              }
                           }
                        }else{
                           if(type_Primative(typeA)){
                              return typeA;
                           }
                        }
                     }else type_err(root, typeA, typeB);
                     break;
                  }
                  case '+':{
                     if(sameType(typeA,typeB)){
                        if(type_NULL(typeA) || type_NULL(typeB)){
                           if(type_NULL(typeA)){
                              if(type_Int(typeB)){
                                 return typeB;
                              }
                           }
                        }else{
                           if(type_Int(typeA)){
                              return typeA;
                           }
                        }
                     }else type_err(root, typeA, typeB);
                     break;
                  }
                  case '-':{
                     if(sameType(typeA,typeB)){
                        if(type_NULL(typeA) || type_NULL(typeB)){
                           if(type_NULL(typeA)){
                              if(type_Int(typeB)){
                                 return typeB;
                              }
                           }
                        }else{
                           if(type_Int(typeA)){
                              return typeA;
                           }
                        }
                     }else type_err(root, typeA, typeB);
                     break;
                  }
                  case '*':{
                     if(sameType(typeA,typeB)){
                        if(type_NULL(typeA) || type_NULL(typeB)){
                           if(type_NULL(typeA)){
                              if(type_Int(typeB)){
                                 return typeB;
                              }
                           }
                        }else{
                           if(type_Int(typeA)){
                              return typeA;
                           }
                        }
                     }else type_err(root, typeA, typeB);
                     break;
                  }
                  case '/':{
                     if(sameType(typeA,typeB)){
                        if(type_NULL(typeA) || type_NULL(typeB)){
                           if(type_NULL(typeA)){
                              if(type_Int(typeB)){
                                 return typeB;
                              }
                           }
                        }else{
                           if(type_Int(typeA)){
                              return typeA;
                           }
                        }
                     }else type_err(root, typeA, typeB);
                     break;
                  }
                  case '%':{
                     if(sameType(typeA,typeB)){
                        if(type_NULL(typeA) || type_NULL(typeB)){
                           if(type_NULL(typeA)){
                              if(type_Int(typeB)){
                                 return typeB;
                              }
                           }
                        }else{
                           if(type_Int(typeA)){
                              return typeA;
                           }
                        }
                     }else type_err(root, typeA, typeB);
                     break;
                  }
               }
            }
            break;
         }
         case 10:{  //unop 
            typeA = checkType(root->children[0]->children[0]); break; } 
         case 11:{  //variable checkType
         
         
             break; }  //variable 
         case 12:{  //new 
             break; }  //new 
         case 13:{ break; }//call 
         case 20:{ root->attributes[ATTR_typeid] = true; 
            break; }//typeid
         
         case 0:{     //default case 
            for (size_t c = 0; c < root->children.size(); ++c) {
               //printf("default_case = %d\n"); 
               typeStr = checkType (root->children[c]);
            }//else block
            break;
         }
      }
   }
   return typeStr;
}

static void ast_sym(astree* root, size_t child, size_t i){
   astree* t1 = root->children[child]->children[i];
   temp_sym = new_symbol( t1->children[A]->attributes,
                          t1->children[A]->lexinfo->c_str(),
                          t1->lexinfo->c_str(),   
                          t1->children[A]->filenr,
                          t1->children[A]->linenr,
                          t1->children[A]->offset);
}

static void reset(){
   depth = 0;
   block_nr = 0;
   next_block = 1;
   fprintf (symout, "\n");
}

static void bnp(){
   block_nr++;
   next_block++;
   depth++;
}

/*astree* add_Array(astree* root){
   string tempStr = root->children[0]->children[0]->lexinfo->c_str();
   tempStr.append(root->children[0]->
               children[0]->children[0]->lexinfo->c_str());
   //A = 1;
   printf("array lexinfo = %s", tempStr.c_str());
   return root;
}*/

static void make_symtable (astree* root){
   if(root == NULL) return;
   for(size_t child = 0; child < root->children.size(); ++child){
      int s = root->children[child]->symbol;
      const char* curr_sym = get_yytname_noT(s);
      switch ( checkLex(curr_sym) ) {
         case 1:{   //struct def 
            astree* t1 = root->children[0];
            symbol* temp = new_symbol(t1->attributes,
                              t1->children[0]->lexinfo->c_str(),
                              t1->lexinfo->c_str(),
                              t1->filenr,
                              t1->linenr,
                              t1->offset);
            dump_symtable (temp);
            bnp();
 for(size_t i=child+1; i<root->children[child]->children.size(); i++) {
               ast_sym(root, child, i);
               temp_sym->block_nr = block_nr;
               dump_symtable (temp_sym);
            }
            reset();
            break;
         }
         case 2:{   //decl
         //if(root->children[0]->children[0]->symbol == TOK_NEWARRAY){
            //   add_Array(root);
            //}
            ast_sym(root, child, 0);
            temp_sym->block_nr = block_nr;
            dump_symtable (temp_sym);
            A=0;
            break;
         }
         case 3:{   //function
         //if(root->children[0]->children[0]->symbol == TOK_NEWARRAY){
            //   add_Array(root);
            //}
            ast_sym(root, child, 0);
            dump_symtable (temp_sym);
            A=0;
            make_symtable(root->children[child]); 
            reset();
            break;
         }
         case 4:{   //vardecl
            //if(root->children[0]->children[0]->children[0]->symbol
            // == TOK_NEWARRAY){
            //   add_Array(root);
            //}
            ast_sym(root, child, 0);
            temp_sym->block_nr = block_nr;
            dump_symtable (temp_sym);
            A=0;
            break;
         }
         case 5:{   //block
            bnp();
            make_symtable(root->children[child]); 
            depth--;
            break;         
         }       
         case 6:{  //while
            //fprintf (symout, "WHILE\n");
            make_symtable(root->children[child]); 
            break;         
         }
         case 7:{   //if
            //fprintf (symout, "IF\n");
            break;         
         }
         case 8:{  // else
            //fprintf (symout, "ELSE\n");
            break;         
         }
         case 9:{ //Binop
            //fprintf (symout, "BINOP\n");
            break;         
         }
         case 10:{  //unop
            //fprintf (symout, "UNOP\n");
            break;         
         }
         case 11:{  //variable
            //fprintf (symout, "VARIABLE\n");
            break;         
         }
         case 12:{  //new
            //fprintf (symout, "NEW\n");
            break;         
         }
         case 13:{  //call
            //fprintf (symout, "CALL\n");
            //make_symtable(root->children[child]); 
            break;         
         }
         case 14:{  //ident
            //fprintf (symout, "IDENT\n");
            break;         
         }
         case 15:{  //declid
            //fprintf (symout, "DECLID\n");
            break;         
         }
         case 16:{  //prototype
            //fprintf (symout, "PROTOTYPE\n");
            ast_sym(root, child, 0);
            dump_symtable (temp_sym);
            make_symtable(root->children[child]); 
            break;
         }
         case 17:{  //parameters list
            size_t j = 0;
            bnp();
 for(size_t i=child; i<=root->children[child]->children.size(); i++) {
               root->children[child]->attributes[13] = true;
               ast_sym(root, child, j);
               temp_sym->block_nr = block_nr;
               dump_symtable (temp_sym);
               j++;
            } 
            block_nr--;
            next_block--;
            depth--;
            fprintf (symout, "\n");
            break;
         }
         case 18:{ //IF.ELSE
            make_symtable(root->children[child]); 
            break;         
         }
         case 19:{  // return
            //fprintf (symout, "RETURN\n");
            make_symtable(root->children[child]); 
            break;         
         }
         default:{
            //printf("default\n");
            break;
         }  
      }
      //for (size_t child = 0; child < root->children.size(); ++child) {
      //}
   }
}

void make_sym (astree* root){
   //temp_Table = glob_Table;
   make_symtable(root);
   //dump_symtable(glob_Table);
   fflush (NULL);
}







































