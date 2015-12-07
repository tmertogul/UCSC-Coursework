#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <string> 
#include <vector>
#include <bitset>

#include "auxlib.h"
#include "symtable.h"

using namespace std;

struct astree {
   int symbol;               // token code
   size_t filenr;            // index into filename stack
   size_t linenr;            // line number from source code
   size_t offset;            // offset of token with current line
   const string* lexinfo;    // pointer to lexical information
   vector<astree*> children; // children of this n-way node
   
   attr_bitset attributes;
   //pointer to structure table node, initialized to NULL
   size_t block_nr; 
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

void check_symtable(astree* root);
astree* funcsearch(astree* root);
void make_sym (astree* root);
astree* checkATTR(astree* tree);
void dump_attr(FILE* outfile, astree* ast);  
attr_bitset copy_ATTR(attr_bitset root, attr_bitset child);
string checkType(astree* root);


#endif
