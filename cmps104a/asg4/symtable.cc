// Import the relevant STL classes
#include <bitset>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "astree.h"
#include "symtable.h"

// Instead of writing "std::string", we can now just write "string"
using namespace std;

extern FILE *symout;
extern size_t depth;
extern size_t block_nr;
extern size_t next_block;
//int next_block = 1;
//extern FILE *symout;
//symbol_table *glob_Table = new symbol_table(NULL);
//symbol_table *temp_Table;

symbol* new_symbol (attr_bitset attributes, string name, string type,
                    size_t filenr, size_t linenr, size_t offset) {  
   symbol* sym = new symbol();
   sym->name = name;
   sym->type = type;
   sym->attributes = attributes;
   sym->fields = NULL;
   sym->filenr = filenr;
   sym->linenr = linenr;
   sym->offset = offset;
   //sym->block_nr = block_nr;
   sym->block_nr = 0;
   sym->parameters = NULL;
   //sym->lexinfo = intern_stringset (lexinfo);
   //tree->attributes = 0;
   return sym;
}

static void dump_attr(FILE* outfile, symbol* node){
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
               fprintf (outfile, "\"%s\" ", node->name.c_str());
               break;}
            case ATTR_typeid :{ //fprintf (outfile, "\"typeid\" "); 
               fprintf (outfile, "struct "); 
               fprintf (outfile, "\"%s\" ", node->type.c_str());
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

static void dump_symbol (symbol* sym) {
   if (sym == NULL) return;
   for (size_t b=0; b<depth; b++) {
      fprintf (symout, "%s", "  ");
   }
   fprintf (symout, "%s (%ld.%ld.%ld) ", 
   //fprintf (symout, "%s (%ld.%ld.%ld) {%ld} %s\n", 
               sym->name.c_str(), 
               sym->filenr, sym->linenr, sym->offset); 
   if (sym->attributes[ATTR_field]){
      fprintf (symout, "field {%s} ", sym->type.c_str());
   } else{ fprintf (symout, "{%ld} ", sym->block_nr); }
   dump_attr(symout, sym);
   fprintf (symout, "\n");
   return;

}

void dump_symtable (symbol* root) {
   dump_symbol (root);
   fflush (NULL);
}























