#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <bitset>

using namespace std;

#include <assert.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#include "astree.h"
#include "auxlib.h"
//#include "emit.h" 
#include "lyutils.h"
#include "stringset.h"
#include "symtable.h"

const string cpp_name = "/usr/bin/cpp";
const size_t LINESIZE = 1024;
//extern string base_name;
string base_name;
string yyin_cpp_command;

string flags;
FILE *strout, *tokout, *astout, *symout;

const char *out_file;


//vector<symbol_table*> symbol_stack;

extern symbol_table *glob_Table;

// Open a pipe from the C preprocessor.
// Exit failure if can't.
// Assignes opened pipe to FILE* yyin.
//void yyin_cpp_popen (string filename, string flags) {
void yyin_cpp_popen (const char* filename){
   yyin_cpp_command = cpp_name;
   yyin_cpp_command += " ";
   yyin_cpp_command += flags;
   yyin_cpp_command += "\"";
   //yyin_cpp_command += " " + flags + " ";
   yyin_cpp_command += filename;
   yyin_cpp_command += "\"";
   yyin = popen (yyin_cpp_command.c_str(), "r");
   DEBUGF('c', ("  D: CPP Command String: "+string(yyin_cpp_command)+
                                                   "\n").c_str() );
   if (yyin == NULL) {
      syserrprintf (yyin_cpp_command.c_str());
      exit (get_exitstatus());
   }
   scanner_newfilename( filename );
}

void yyin_cpp_pclose (void) {
   int pclose_rc = pclose (yyin);
   //eprint_status (yyin_cpp_command.c_str(), pclose_rc);    // -------
   //if (pclose_rc != 0) exit(EXIT_FAILURE);
   if (pclose_rc != 0) set_exitstatus (EXIT_FAILURE);
}

/*bool want_echo () {
   return not (isatty (fileno (stdin)) and isatty (fileno (stdout)));
}*/

void scan_opts (int argc, char** argv) {
   int option;
   opterr = 0;
   yy_flex_debug = 0;
   yydebug = 0;
   for(;;) {
      option = getopt (argc, argv, "@:ely");
      if (option == EOF) break;
      switch (option) {
         case '@': set_debugflags (optarg);       break;
         case 'D': flags = "-D" + string(optarg); break;
         case 'l': yy_flex_debug = 1;             break;
         case 'y': yydebug = 1;                   break;
         default:  errprintf ("%:bad option (%c)\n", optopt); break;
      }
   }
}

string get_filename (string name){
   string filename;
   unsigned found = name.find_last_of("/\\");
   name = name.substr(found+1);
   name.erase(name.find_last_of("."), string::npos);
   base_name = name;
   return name;
}

void open_outfiles(){
   out_file = (string(base_name)+".str").c_str();
   strout = fopen( out_file, "w" );
   out_file = (string(base_name)+".tok").c_str();
   tokout = fopen( out_file, "w" );
   out_file = (string(base_name)+".ast").c_str();
   astout = fopen( out_file, "w" );   
   out_file = (string(base_name)+".sym").c_str();
   symout = fopen( out_file, "w" );
}

void close_outfiles(){
   fclose( strout );
   fclose( tokout );
   fclose( astout );
   fclose( symout );
}    

int main (int argc, char** argv) {
   //struct options options = {/*false,*/ false, NULL};
   int parsecode = 0;
   set_execname (argv[0]);
 
   DEBUGSTMT ('m', for (int argi = 0; argi < argc; ++argi) {
      eprintf ("%s%c", argv[argi], argi < argc - 1 ? ' ' : '\n');
   }  );

   if (optind > argc) {
      errprintf ("Usage: %s [-ly] [filename]\n", get_execname());
      exit (get_exitstatus());
   } 
 
   string prog_name = argv[argc-1];
   get_filename (prog_name);
   //printf ("base_name = %s\n", base_name.c_str());
   scan_opts (argc, argv); 
   yyin_cpp_popen (prog_name.c_str());
   
   open_outfiles();

   parsecode = yyparse();
   
   if (parsecode) {
      errprintf ("%:parse failed (%d)\n", parsecode);
   }else {
      DEBUGSTMT ('a', dump_astree (stderr, yyparse_astree); );
      //emit_sm_code (yyparse_astree);
   }
   
   dump_stringset (strout);
   
   checkType(yyparse_astree);

   
   dump_astree(astout, yyparse_astree);
                           // -------------
   make_sym(yyparse_astree);
   //dump_symbol(symout, glob_Table, 0);

                            // -------------
   //check_symtable(yyparse_astree);                 // -------------

   close_outfiles();

   //free_ast (yyparse_astree);

   yyin_cpp_pclose();

   //DEBUGSTMT ('s', dump_stringset (stderr); );
   yylex_destroy();
   
   //test_function();
   
   /*for (size_t s=0; s<prog_name.length(); s++) {
      printf(" ");
   }
   printf ("    - done, SHOWER\n");
*/
   return get_exitstatus();
   //return EXIT_SUCCESS;
}
















