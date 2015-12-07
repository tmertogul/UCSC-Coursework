// $Id: cppstrtok.cpp,v 1.3 2014-10-07 18:09:11-07 - - $

// Use cpp to scan a file and print line numbers.
// Print out each input line read in, then strtok it for
// tokens.

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

#include <assert.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

//#include "astree.h"
#include "auxlib.h"
//#include "emit.h"
//#include "lyutils.h"
#include "stringset.h"

const string cpp_name = "/usr/bin/cpp";
const size_t LINESIZE = 1024;
string yyin_cpp_command;
FILE* OCfile = nullptr;
string strext = ".str";
string flags;
fstream strout;
int yy_flex_debug;
int yydebug;
// taken from lyutils in order for it to work

struct options{
   //bool badopt;
   bool suppresscode;
   char* D_string;
};

// Chomp the last character from a buffer if it is delim.
void chomp (char* string, char delim) {
   size_t len = strlen (string);
   if (len == 0) return;
   char* nlpos = string + len - 1;
   if (*nlpos == delim) *nlpos = '\0';
}
// Run cpp against the lines of the file.
void cpplines (FILE* pipe, char* filename) {
   int linenr = 1;
   char inputname[LINESIZE];
   strcpy (inputname, filename);
   for (;;) {
      char buffer[LINESIZE];
      char* fgets_rc = fgets (buffer, LINESIZE, pipe);
      if (fgets_rc == NULL) break;
      chomp (buffer, '\n');
      //printf ("%s:line %d: [%s]\n", filename, linenr, buffer);
      // http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
      int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"",
                              &linenr, filename);
      if (sscanf_rc == 2) {
         continue;
      }
      char* savepos = NULL;
      char* bufptr = buffer;
      for (int tokenct = 1;; ++tokenct) {
         char* token = strtok_r (bufptr, " \t\n", &savepos);
         bufptr = NULL;
         if (token == NULL) break;
         /*printf ("token %d.%d: [%s]\n",
                 linenr, tokenct, token);*/
         (void) intern_stringset (token);
      }
      ++linenr;
   }
}

// Open a pipe from the C preprocessor.
// Exit failure if can't.
// Assignes opened pipe to FILE* yyin.
void yyin_cpp_popen (string filename, string flags) {
   yyin_cpp_command = cpp_name;
   yyin_cpp_command += " ";
   yyin_cpp_command += flags;
   yyin_cpp_command += "\"";
   yyin_cpp_command += filename;
   yyin_cpp_command += "\"";
   OCfile = popen (yyin_cpp_command.c_str(), "r");
   if (OCfile == NULL) {
      cerr << "Error: Couldn't open file: " << filename << endl;
      exit(EXIT_FAILURE);
      //syserrprintf (yyin_cpp_command.c_str());
      //exit (get_exitstatus());
   }
}

void yyin_cpp_pclose (void) {
   int pclose_rc = pclose (OCfile);
   //eprint_status (yyin_cpp_command.c_str(), pclose_rc);
   if (pclose_rc != 0) set_exitstatus (EXIT_FAILURE);
}

/*bool want_echo () {
   return not (isatty (fileno (stdin)) and isatty (fileno (stdout)));
}*/
string get_filename (string filename){
    unsigned found = filename.find_last_of("/\\");
    filename = filename.substr(found+1);
    filename.erase(filename.find_last_of("."), string::npos);
    filename += strext;
    //printf ("%s = filename\n", filename.c_str());
    strout.open (filename, ios::out );
    return filename;
}

void scan_opts (int argc, char** argv, struct options *options) {
    int option;
    opterr = 0;
    yy_flex_debug = 0;
    yydebug = 0;
    for(;;) {
        option = getopt (argc, argv, "@:ely");
        if (option == EOF) break;
        switch (option) {
            case '@': set_debugflags (optarg);      break;
            case 'D': options->suppresscode = true;
                    options->D_string = optarg;      break;
            case 'l': yy_flex_debug = 1;             break;
            case 'y': yydebug = 1;                   break;
            default:  errprintf ("%:bad option (%c)\n", optopt); break;
        }
    }
    //const char* file = optind == argc ? "-" : argv[optind];
    //string filename = file;   
    if (optind > argc) {
        cerr << "Usage: " << get_execname() 
            << " [-@:D:ly] [filename]" << endl;
        //errprintf ("Usage: %s [-ly] [filename]\n", get_execname());
        exit (get_exitstatus());
    }
   //const char* filename = optind == argc ? "-" : argv[optind];
   string filename = optind == argc ? "-" : argv[optind];
   filename = get_filename (filename);
   //cout << filename << " = filename" << endl;
   yyin_cpp_popen (filename, flags);
   /*DEBUGF ('m', "filename = %s, OCfile = %p, fileno (OCfile) = %d\n",
           filename, OCfile, fileno (OCfile));*/
   //scanner_newfilename (filename);
}

int main (int argc, char** argv) {
    struct options options = {/*false,*/ false, NULL};
    //int parsecode = 0;
    set_execname (argv[0]);
    DEBUGSTMT ('m',
        for (int argi = 0; argi < argc; ++argi) {
            eprintf ("%s%c", argv[argi], argi < argc - 1 ? ' ' : '\n');
        }
    );
    scan_opts (argc, argv, &options);
    vector<string> args (&argv[1], &argv[argc]);
    for (int argi = 1; argi < argc; ++argi) {
        char* filename = argv[argi];
        string command = cpp_name + " " + filename;
        //printf ("command=\"%s\"\n", command.c_str());
        FILE* pipe = popen (command.c_str(), "r");
        //const string* hashtable = intern_stringset (arg.c_str());
        if (pipe == NULL) {
            syserrprintf (command.c_str());
        }else {
            cpplines (pipe, filename);
            int pclose_rc = pclose (pipe);
            eprint_status (command.c_str(), pclose_rc);
        }
    }
    //vector<string> args (&argv[1], &argv[argc]);
    /*for (const string& arg: args) {
       const string* str = intern_stringset (arg.c_str());
       //cout << "intern(" << arg << ") returned " << str
       //     << "->\"" << *str << "\"" << endl;
    }*/
    dump_stringset (strout);
    strout.close();
    return EXIT_SUCCESS;
    //return get_exitstatus();
}

