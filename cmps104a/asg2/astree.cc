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
//#include "symtable.h" 
 
int next_block = 1;

astree* new_astree (int symbol, int filenr, int linenr,
                    int offset, const char* lexinfo) {
   astree* tree = new astree();
   tree->symbol = symbol;
   tree->filenr = filenr;
   tree->linenr = linenr;
   tree->offset = offset;
   tree->lexinfo = intern_stringset (lexinfo);

   DEBUGF ('f', "astree %p->{%d:%d.%d: %s: \"%s\"}\n",
           tree, tree->filenr, tree->linenr, tree->offset,
           get_yytname (tree->symbol), tree->lexinfo->c_str()); 
   return tree;
}

astree* adopt1 (astree* root, astree* child) {
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

static void dump_node (FILE* outfile, astree* node) {
   //fprintf (outfile, "---\n");
   const char *tname = get_yytname (node->symbol);
   if (strstr (tname, "TOK_") == tname) tname += 4;
   fprintf (outfile, "%s \"%s\" (%ld.%ld.%ld) {} (0.0.0.)", tname, 
            node->lexinfo->c_str(), node->filenr, node->linenr, 
            node->offset);
   bool need_space = false;
   for (size_t child = 0; child < node->children.size();
        ++child) {
      if (need_space) fprintf (outfile, " ");
      need_space = true;
   }
}

static void dump_astree_rec (FILE* outfile, astree* root, int depth) {
   if (root == NULL) return;
   //fprintf (outfile, "%*s%s ", depth * 3, "",
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







