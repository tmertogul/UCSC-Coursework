
#include <vector>
#include <string>
using namespace std;
 
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "lyutils.h"
#include "auxlib.h"
#include "stringset.h"

astree* yyparse_astree = NULL;
int scan_linenr = 1;
int scan_offset = 0;
bool scan_echo = false;
vector<string> included_filenames;

const string* scanner_filename (int filenr) {
   return &included_filenames.at(filenr);
}

void scanner_newfilename (const char* filename) {
   included_filenames.push_back (filename);
}

void scanner_newline (void) {
   ++scan_linenr;
   scan_offset = 0;
}

void scanner_setecho (bool echoflag) {
   scan_echo = echoflag;
}


void scanner_useraction (void) {
   if (scan_echo) {
      if (scan_offset == 0) printf (";%5d: ", scan_linenr);
      printf ("%s", yytext);
   }
   scan_offset += yyleng;
}

void yyerror (const char* message) {
   assert (not included_filenames.empty());
   errprintf ("%:%s: %d: %s\n",
              included_filenames.back().c_str(),
              scan_linenr, message);
}

void scanner_badchar (unsigned char bad) {
   char char_rep[16];
   sprintf (char_rep, isgraph (bad) ? "%c" : "\\%03o", bad);
   errprintf ("%:%s: %d: invalid source character (%s)\n",
              included_filenames.back().c_str(),
              scan_linenr, char_rep);
}
 
void scanner_badtoken (char* lexeme) {
   errprintf ("%:%s: %d: invalid token (%s)\n",
              included_filenames.back().c_str(),
              scan_linenr, lexeme);
}

int yylval_token (int symbol) {
   int offset = scan_offset - yyleng;
   yylval = new_astree (symbol, included_filenames.size() - 1,
                        scan_linenr, offset, yytext);
   //yylval->filenr-=1;          // CPP preprocessor reading extra file
   
   fprintf (tokout, "%2ld %3ld.%03ld %4d  %-15s \(%s)\n",
                    yylval->filenr, yylval->linenr, yylval->offset,
                    yylval->symbol, get_yytname( yylval->symbol ),
                    yylval->lexinfo->c_str()); 
   return symbol;
}

void error_destructor (astree* tree) {
   if (tree == yyparse_astree) return;
   DEBUGSTMT ('a', dump_astree (stderr, tree); );
   free_ast (tree);
}

astree* new_parseroot (void) {
   yyparse_astree = new_astree (TOK_ROOT, 0, 0, 0, "");
   return yyparse_astree;
}

astree* new_prototype (astree* tree) {
   astree* prototype = new_astree (TOK_PROTOTYPE, tree->filenr, 
                                   tree->linenr, tree->offset, "");
   return prototype; 
}

astree* new_function (astree* tree) {
   astree* function = new_astree (TOK_FUNCTION, tree->filenr, 
                                   tree->linenr, tree->offset, "");
   return function; 
}

astree* new_block (astree* tree) {
   astree* block = new_astree (TOK_BLOCK, tree->filenr, 
                                   tree->linenr, tree->offset, "");
   return block; 
}

astree* new_stmts (astree* tree) {
   astree* stmts = new_astree (TOK_TIMER, tree->filenr, 
                                   tree->linenr, tree->offset, "");
   return stmts; 
}


void scanner_include (void) {
   scanner_newline();
   char filename[strlen (yytext) + 1];
   int linenr;
   fprintf(tokout, "%s\n", yytext);
   int scan_rc = sscanf (yytext, "# %d \"%[^\"]\"",
                         &linenr, filename);
   if (scan_rc != 2) {
      errprintf ("%: %d: [%s]: invalid directive, ignored\n",
                 scan_rc, yytext);
   }else {
      //printf (";# %d \"%s\"\n", linenr, filename);
      scanner_newfilename (filename);
      scan_linenr = linenr - 1;
      DEBUGF ('m', "filename=%s, scan_linenr=%d\n",
              included_filenames.back().c_str(), scan_linenr);
   }
}

RCSC("$Id: lyutils.cc,v 1.1 2014-11-29 12:58:44-08 - - $")

