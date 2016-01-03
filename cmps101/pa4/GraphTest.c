/*
Tim Mertogul
1331402
tmertogu
CMPS101 Summer 2014
08/03/14
PA4
GraphTest.c
Tests Graph perations in isolation
*/


//-----------------------------------------------------------------------------
// 
// This program does not exercise all functions in your Graph ADT, but it 
// does a pretty good job of testing BFS().  If your output differs from 
// the above, you have a logical problem in either your Graph or List ADT.
// 
// Remember you are required to submit a file named GraphTest.c with pa4 that
// exercises your Graph functions.  Do not submit this file.
//
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List.h"
#include "Graph.h"

int main(int argc, char* argv[]){
	
	Graph g0 = newGraph(6);
	
	//get path
	//BFS
	//add Arc
	
	
	addEdge(g0, 1, 2);
	addEdge(g0, 1, 3);
	addEdge(g0, 2, 4);
	addEdge(g0, 2, 5);
	addEdge(g0, 2, 6);
	addEdge(g0, 3, 4);
	addEdge(g0, 4, 5);
	addEdge(g0, 5, 6);
	printf("|V| or ORDER of G = %d\n", getOrder(g0));
	printf("|E| or SIZE of G = %d\n", getSize(g0));
	printf("Source of G = %d\n", getSource(g0));
	printf("Parent of G = %d\n", getParent(g0,3));
	printf("Dist of G = %d\n", getDist(g0,6));
	//printGraph(stout, G);
	
	//makeNull(g0);
	//printf("|V| or ORDER of G = %d\n", getOrder(g0));
	//printf("|E| or SIZE of G = %d\n", getSize(g0));
	//printGraph(stout, G);




	
	
	
	
	freeGraph(&g0); 

	

	/*
   int i, s, max, min, d, n=35;
   List  C = newList(); // central vertices 
   List  P = newList(); // peripheral vertices 
   List  E = newList(); // eccentricities 
   Graph G = NULL;

   // Build graph G 
   G = newGraph(n);
   for(i=1; i<n; i++){
      if( i%7!=0 ) addEdge(G, i, i+1);
      if( i<=28  ) addEdge(G, i, i+7);
   }
   addEdge(G, 9, 31);
   addEdge(G, 17, 13);
   addEdge(G, 14, 33);

   // Print adjacency list representation of G
   printGraph(stdout, G);

   // Calculate the eccentricity of each vertex 
   for(s=1; s<=n; s++){
      BFS(G, s);
      max = getDist(G, 1);
      for(i=2; i<=n; i++){
         d = getDist(G, i);
         max = ( max<d ? d : max );
      }
      append(E, max);
   }

   // Determine the Radius and Diameter of G, as well as the Central and 
   // Peripheral vertices.
   append(C, 1);
   append(P, 1);
   min = max = front(E);
   moveTo(E,0);
   moveNext(E);
   for(i=2; i<=n; i++){
      d = getElement(E);
      if( d==min ){
         append(C, i);
      }else if( d<min ){
         min = d;
         clear(C);
         append(C, i);
      }
      if( d==max ){
         append(P, i);
      }else if( d>max ){
         max = d;
         clear(P);
         append(P, i);
      }
      moveNext(E);
   }

   // Print results 
   printf("\n");
   printf("Radius = %d\n", min);
   printf("Central vert%s: ", length(C)==1?"ex":"ices");
   printList(stdout, C);
   printf("\n");
   printf("Diameter = %d\n", max);
   printf("Peripheral vert%s: ", length(P)==1?"ex":"ices");
   printList(stdout, P);
   printf("\n"); 

   // Free objects 
   freeList(&C);
   freeList(&P);
   freeList(&E);
   freeGraph(&G); */

   return(0);
}