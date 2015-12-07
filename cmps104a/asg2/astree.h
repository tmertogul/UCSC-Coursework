#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <string> 
#include <vector>
#include <bitset>
using namespace std;

#include "auxlib.h"
//#include "symtable.h"
 
struct astree {
   int symbol;               // token code
   size_t filenr;            // index into filename stack
   size_t linenr;            // line number from source code
   size_t offset;            // offset of token with current line
   const string* lexinfo;    // pointer to lexical information
   vector<astree*> children; // children of this n-way node
};
 
astree* new_astree (int symbol, int filenr, int linenr,
                    int offset, const char* lexinfo);
astree* adopt1 (astree* root, astree* child);
astree* adopt2 (astree* root, astree* left, astree* right);
astree* adopt3 (astree* root, astree* left, astree* middle, 
                astree* right);
astree* stealkids (astree* root, astree* origin);
astree* adoptsym (astree* root, int symbol);
astree* adopt1sym (astree* root, astree* child, int symbol);
astree* adopt2sym (astree* root, astree* left, astree* right, 
                  int symbol);
void dump_astree (FILE* outfile, astree* root);
void yyprint (FILE* outfile, unsigned short toknum, astree* yyvaluep);
void free_ast (astree* tree);
void free_ast2 (astree* tree1, astree* tree2);
void free_ast3 (astree* tree1, astree* tree2, astree* tree3);

//void make_symtable (astree* root);
//void check_symtable(astree* root);
//astree* funcsearch(astree* root);
//bool funcsearch2(astree* root, string type, symbol_table* symTbl);
//string type_convert(string type);


#endif
