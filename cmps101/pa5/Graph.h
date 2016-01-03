/*
Tim Mertogul
1331402
tmertogu
CMPS101 Summer 2014
08/11/14
PA5
Graph.h
Graph ADT header file
*/

//-----------------------------------------------------------------------------
// Graph.h
// Header file for Graph ADT
//-----------------------------------------------------------------------------

#ifndef _Graph_H_INCLUDE_
#define _Graph_H_INCLUDE_
#include"List.h"
#define UNDEF 0;
//#define UNDEF -1;
#define NIL 0;

// Exported type --------------------------------------------------------------
typedef struct GraphObj* Graph;


/* Constructors-Destructors */
Graph newGraph(int n);
void freeGraph(Graph* pG);

/* Access functions */
int getOrder(Graph G);
int getSize(Graph G);
int getParent(Graph G, int u);
int getDiscover(Graph G, int u);
int getFinish(Graph G, int u);

/* Manipulation procedures */
void addArc(Graph G, int u, int v);
void addEdge(Graph G, int u, int v);
void DFS(Graph G, List S);
void Visit(Graph G, int u, List S, int* time);

void strongComponent(Graph G, List S, FILE* out);



/* Other Functions */
Graph transpose(Graph G);
Graph copyGraph(Graph G);
void printGraph(FILE* out , Graph G);


#endif







