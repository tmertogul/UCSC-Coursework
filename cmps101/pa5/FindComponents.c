/*
Tim Mertogul
1331402
tmertogu
CMPS101 Summer 2014
08/11/14
PA5
FindComponents.c
Client Program for Graph ADT
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List.h"
#include "Graph.h"

#define MAX_LEN 300

int main(int argc, char * argv[]){ 
	
	//printf("FindComponents\n");
	int n, i, count=0;
	FILE *in, *out;
	char line[MAX_LEN];
	char tokenlist[MAX_LEN];
	char* token;
	int flag = 0;
	Graph G;
	int vA;
	int vB;
	List S = newList();

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
		int temp = 0; 
		count++;
		n = 0;
		Graph T=NULL;
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
					fprintf(out, "Adjacency list representation of G: \n");
					printGraph(out, G);
					fprintf(out, "\n");
					
					printf("Adjacency list representation of G: \n");
					printGraph(stdout, G);
					printf("\n");
				}
				
				//printList(stdout, S);
				//printf(" = S \n");				
				
				if( isEmpty(S) ){				
					for(i=1; i<=getOrder(G); i++) append(S, i);
				}
				
				DFS(G, S); 
				
				T = transpose(G);
				
				DFS(T, S); 
				
									
				strongComponent(G, S, out);
				

			}	
			else if (flag == 0) { 
				//printf("is this error?\n");
				addArc(G, vA, vB); 
			} 
		}   
	}

   freeGraph(&G);

   fclose(in);
   fclose(out); 

   return(0);
}