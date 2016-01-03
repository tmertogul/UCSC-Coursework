/*
Tim Mertogul
1331402
tmertogu
CMPS101 Summer 2014
08/11/14
PA5
GraphTest.c
Tests Graph perations in isolation
*/


//-----------------------------------------------------------------------------
// 
// 
//
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List.h"
#include "Graph.h"

int main(int argc, char* argv[]){
	
	   int i, n=8;
	   List S = newList();
	   Graph G = newGraph(n);
	   Graph T=NULL, C=NULL;
	
	
  	 for(i=1; i<=n; i++) append(S, i);

 	   addArc(G, 1,2);
 	   addArc(G, 1,5);
 	   addArc(G, 2,5);
 	   addArc(G, 2,6);
	   addArc(G, 3,2);
	   addArc(G, 3,4);
	   addArc(G, 3,6);
	   addArc(G, 3,7);
	   addArc(G, 3,8);
	   addArc(G, 6,5);
	   addArc(G, 6,7);
	   addArc(G, 8,4);
	   addArc(G, 8,7);
	   printGraph(stdout, G);

//	   printList(stdout, S);
	//   printf(" = S \n");

	   DFS(G, S); 
	   fprintf(stdout, "\n");
	   fprintf(stdout, "x:  d  f  p\n");
	   for(i=1; i<=n; i++){
	      fprintf(stdout, "%d: %2d %2d %2d\n", i, getDiscover(G, i), getFinish(G, i), getParent(G, i));
	   }
	   fprintf(stdout, "\n");
	   printList(stdout, S);
	   fprintf(stdout, "\n");


	   T = transpose(G);

	   C = copyGraph(G);
	//printf("copied C\n");

	   fprintf(stdout, "\n");
//	printf("printing C\n");

	   printGraph(stdout, C);
//	printf("PRINTED C\n");

	   fprintf(stdout, "\n");
	   printGraph(stdout, T);
	   fprintf(stdout, "\n");

	   DFS(T, S);
	   fprintf(stdout, "\n");
	   fprintf(stdout, "x:  d  f  p\n");
	   for(i=1; i<=n; i++){
	      fprintf(stdout, "%d: %2d %2d %2d\n", i, getDiscover(T, i), getFinish(T, i), getParent(T, i));
	   }
	   fprintf(stdout, "\n");
	   printList(stdout, S);
	   fprintf(stdout, "\n");

	   freeList(&S);
	   freeGraph(&G);
	   freeGraph(&T);
	   freeGraph(&C);	

   return(0);
}

	
	
/*	   printf("printing null G\n");
	   printGraph(stdout, G);
	   printf("\n");

	   printf("printing null S: ");
       printList(stdout, S);
	   printf("\n");

	   for(i=1; i<=n; i++) append(S, i);
	
	   printf("printing S again: ");
	   printList(stdout, S);
	   printf("\n");

	   //printf("Step 6\n");

	   printf("addArc initiate \n");

	   addArc(G, 1,2);
	   addArc(G, 1,5);
	   addArc(G, 2,5);
	   addArc(G, 2,6);
	   addArc(G, 3,2);
	   addArc(G, 3,4);
	   addArc(G, 3,6);
	   addArc(G, 3,7);
	   addArc(G, 3,8);
	   addArc(G, 6,5);
	   addArc(G, 6,7);
	   addArc(G, 8,4);
	   addArc(G, 8,7);
	   printf("Step 7\n");

	   printGraph(stdout, G); */