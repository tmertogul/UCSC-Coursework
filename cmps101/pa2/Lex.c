/*Tim Mertogul
* 1331402
* CMPS101 Summer14
* 07/09/14
* Lex reads from input file and alphabetices
* Lex.c
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List.h"

#define MAX_LEN 200

int main(int argc, char * argv[]){

   int linecount = 0;  //n, count=0,
   FILE *in, *out;
   char line[MAX_LEN];
   List Lu = newList();
   //List Ls = newList();

   // check command line for correct number of arguments
   if( argc != 3 ){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
   }
   //open file, count tokens, close file
   in = fopen(argv[1], "r");
   out = fopen(argv[2], "w");
   if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }
   if( out==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
   }
   while( fgets(line, MAX_LEN, in) != NULL)  {
	  linecount++;
   }
   //printf("linecount = %d \n", linecount);

   rewind(in);
   //char Lu[linecount] [MAX_LEN];
   char words[linecount] [MAX_LEN];
   char copy[linecount] [MAX_LEN];

   for (int i = 0; i < linecount; i++){
	  fgets(line,MAX_LEN,in);
	  strcpy(words[i], line);
	  strcpy(copy[i], line);
   }
/*
for (int j=0; j<linecount; j++){
   fprintf(out, "%s\n", words[j]);
}  */ 


	for(int i=0; i<linecount; i++){
		append(Lu,i);
	}

   //printList(out, Lu);

   /* close files */
   fclose(in);
   in = NULL;

   for(int x=1; x<linecount; x++){
		//String tempy = words[x];
		char tempy[MAX_LEN]; // = words[x];
		strcpy(tempy, words[x]);

		moveTo(Lu,x);
		//int Pt = getIndex(Lu);
		int Ti;
		int jk;
		//for (jk=x-1; jk>=0 && tempy.compareTo(words[jk])<0; jk--){
		for (jk=x-1; jk>=0 && strcmp(tempy, words[jk]) <0; jk--){
			moveTo(Lu,x);
			Ti = getElement(Lu);
			delete(Lu);
			moveTo(Lu,jk);
			insertBefore(Lu,Ti);
			x--;
			strcpy(words[jk+1], words[jk]);
			//words[jk+1] = words[jk];
		}
		if(getIndex(Lu) >= 0){
			movePrev(Lu);
		}
		strcpy(words[jk+1], tempy);
		//words[jk+1] = tempy;
		//free(tempy);
	}
	int Ti = 0;
	/*while (Ti < words.length ){
		System.out.println("a[T] = "+words[Ti]);
		Ti++;
	}
	Ti = 0;*/
	while (Ti < linecount ){
		moveTo(Lu,Ti);
		fprintf(out, "%s", copy[ getElement(Lu) ]);
		Ti++;
	}
	moveTo(Lu,0);


   fclose(out);
   out=NULL;

   return(0);
}






