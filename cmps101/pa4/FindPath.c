/*
Tim Mertogul
1331402
tmertogu
CMPS101 Summer 2014
08/03/14
PA4
FindPath.c
Client Program for Graph ADT
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List.h"
#include "Graph.h"
#define MAX_LEN 300


int main(int argc, char * argv[]){ 
   int n, count=0;
   FILE *in, *out;
   char line[MAX_LEN];
   char tokenlist[MAX_LEN];
   char* token;
   int flag = 0;
   Graph G;

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
      int vA;
      int vB;
      int temp = 0; 
      count++;
      n = 0;
      token = strtok(line, " \n");
      tokenlist[0] = '\0';
      while( token!=NULL ){
         strcat(tokenlist, " ");
         strcat(tokenlist, token);
         strcat(tokenlist, "\n");
         n++;
         if (n == 1) {
            vA = atoi(token);
         }
         if (n == 2) {   
            vB = atoi(token);
         }
         token = strtok(NULL, " \n");
      }
      if (count == 1){  
         temp = atoi(tokenlist);
         G = newGraph(temp);
	   }
      else {  
         if (vA == 0 && vB == 0){ 
            flag = flag + 1;
            if(flag == 1){
               printGraph(out, G);
            }
         }  
         if (flag == 0) { 
            addEdge(G, vA, vB); 
         } 
         else if (flag == 1) { 
            List fL = newList();
            BFS(G, vA);
            getPath(fL, G, vB);
            fprintf(out, "\n"); 
            fprintf(out, "The distance from %d to %d is %d \n", vA, vB, getDist(G, vB));
            fprintf(out, "A shortest %d-%d path is: ", vA, vB);
            printList(out, fL);
            fprintf(out, "\n");
            printf("\n");
            freeList(&fL);
         } 
         else if (flag == 2) {
         } 
      }   
   }

   freeGraph(&G);

   fclose(in);
   fclose(out); 

   return(0);
}