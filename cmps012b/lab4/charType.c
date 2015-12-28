#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>

#include<string.h>

#define MAX_STRING_LENGTH 500

// function prototype 
void extract_chars(char* s, char* a, char* d, char* p, char* w);
//
// // function main which takes command line arguments 
int main(int argc, char* argv[]){
   FILE* in;        // handle for input file                  
   FILE* out;       // handle for output file                 
   char* line;      // string holding input line              
   char* alpha; // string holding all alphabetic chars 
   char* digit; // string holding all digits
   char* punct; // string holding all punctuation chars
   char* white; // string holding all whitespace

   // check command line for correct number of arguments 
   if( argc != 3 ){
      printf("Usage: %s input-file output-file\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   // open input file for reading 
   if( (in=fopen(argv[1], "r"))==NULL ){
      printf("Unable to read from file %s\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   // open output file for writing 
   if( (out=fopen(argv[2], "w"))==NULL ){
      printf("Unable to write to file %s\n", argv[2]);
      exit(EXIT_FAILURE);
   }

   // allocate strings line and alpha_num on the heap 
   line = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
   alpha = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
   digit = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
   punct = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
   white = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
   assert( line!=NULL && alpha!=NULL && digit!=NULL && punct!=NULL && white!=NULL );
   //assert( alpha!=NULL );
   //assert( digit!=NULL );
   //assert( punct!=NULL );
   //assert( white!=NULL );

   int ln = 1;
   // read each line in input file, extract alpha-numeric characters 
   while( fgets(line, MAX_STRING_LENGTH, in) != NULL ){
      extract_chars(line, alpha, digit, punct, white);
      int lenA = strlen(alpha);
      int lenD = strlen(digit);
      int lenP = strlen(punct);
      int lenW = strlen(white);
      //char sA = print_S(alpha);
      //char sD = print_S(digit);
      //char sP = print_S(punct);
      //char sW = print_S(white);

      fprintf(out, "line %d contains:\n", ln);

      fprintf(out, "%d", lenA);
      fprintf(out, " alphabetic character");
       if(lenA != 1) fprintf(out, "s");
      fprintf(out, ": %s\n", alpha);

      fprintf(out, "%d", lenD);
      fprintf(out, " numeric character");
       if(lenD != 1) fprintf(out, "s");
      fprintf(out, ": %s\n", digit);

      fprintf(out, "%d", lenP);
      fprintf(out, " punctuation character");
       if(lenP != 1) fprintf(out, "s");
      fprintf(out, ": %s\n", punct);

      fprintf(out, "%d", lenW);
      fprintf(out, " whitespace character");
       if(lenW != 1) fprintf(out, "s");
      fprintf(out, ": %s\n", white);
      ln++;
   }

   // free heap memory 
   free(line);
   free(alpha);
   free(digit);
   free(punct);
   free(white);
   //free(assert);

   // close input and output files 
   fclose(in);
   fclose(out);

   return EXIT_SUCCESS;
}


// function definition 
void extract_chars(char* s, char* a, char* d, char* p, char* w){
   int i=0, j=0, k=0, m=0, n=0;
   while(s[i]!='\0' && i<MAX_STRING_LENGTH){
      if( isalpha((int)s[i]) ) {
         a[j++] = s[i];
         i++;
      }
      else if( isdigit((int)s[i]) ) {
         d[k++] = s[i];
         i++;
      }
      else if( ispunct((int)s[i]) ) {
         p[m++] = s[i];
         i++;
      }
      else if( isspace((int)s[i]) ) {
         w[n++] = s[i];
         i++;
      }
      
   }
   a[j] = '\0';
   d[k] = '\0';
   p[m] = '\0';
   w[n] = '\0';

}


