/*
Tim Mertogul
1331402
tmertogu
CMPS101 Summer 2014
08/03/14
PA4
Graph.c
Graph ADT
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Graph.h"

typedef struct GraphObj{
		int order; 
		int size; 
		int source; 
		char* color; 
		int* dist; 
		int* parent; 
		List* adj; 
} GraphObj;
	
Graph newGraph(int n){
	Graph G = malloc(sizeof(GraphObj));
	G->order = n;
	G->size = INF;
	G->source = NIL;
	G->color = calloc(n+1, sizeof(char));
	G->dist = calloc(n+1, sizeof(int));  
	G->parent = calloc(n+1, sizeof(int));
	G->adj = calloc(n+1, sizeof(List));
	int i;
	for(i = 1; i <= n; i++){
		G->color[i] = 'w';
		G->dist[i] = INF;
		G->parent[i] = NIL;
		G->adj[i] = newList();
	}
	G->size = G->size+1;
return G; 
}

void freeGraph(Graph* pG){
	if( pG!=NULL && *pG!=NULL ){
		int i;
		for(i = 0; i < (*pG)->order; i++){
			if((*pG)->adj[i] != NULL){
				freeList(&((*pG)->adj[i]));
			}
		}
	}
	free((*pG)->color);
	free((*pG)->dist);
	free((*pG)->parent);
	*pG = NULL;
} 


int getOrder(Graph G){  
	if( G == NULL ){
		printf("Graph Error: calling getOrder() on null Graph \n");
		exit(1);
	}
	return(G->order);
} 

int getSize(Graph G){ 
	if( G == NULL ){
		printf("Graph Error: calling getSize() on null Graph \n");
		exit(1);
	}
	return G->size;
} 

int getSource(Graph G){ 
	if( G == NULL ){
		printf("Graph Error: calling getSource() on null Graph \n");
		exit(1);
	}
	return G->source;
} 

int getParent(Graph G, int u){ 
	if( G == NULL ){
		printf("Graph Error: calling getParent() on null Graph \n");
		exit(1);
	}
	return G->parent[u];
}

int getDist(Graph G, int u){ 
	if( G == NULL ){
		printf("Graph Error: calling getDist() on null Graph \n");
		exit(1);
	}
	return G->dist[u];
}

void getPath(List L, Graph G, int u){ 
	if( G == NULL ){
		printf("Graph Error: calling getPath() on null Graph \n");
		exit(1);
	}
	if(getSource(G) != -2 ){
		if(G->dist[u] != -1 ){
			if(G->source == u){
				prepend(L, u);
				return;
			}
			prepend(L, u);
			int z = G->parent[u];
			while(z != G->source){
				prepend(L, z);
				z = G->parent[z];
			}
			prepend(L, G->source);
		}
		else{
			prepend(L, -2 );
		}	
	}
}

/*** Manipulation procedures ***/
void makeNull(Graph G){
	int i;
	for(i = 1; i <= getOrder(G); i++){
		G->color[i] = 'w';
		G->dist[i] = INF;
		G->parent[i] = NIL;
		clear(G->adj[i]);
	}
	
} 

void addEdge(Graph G, int u, int v){ 
	G->parent[v] = u;
	append(G->adj[u], v);			
	append(G->adj[v], u);			
	G->size = G->size + 1;

} 

void addArc(Graph G, int u, int v){
	G->parent[v] = u;
	append(G->adj[u], v);			
	G->size = G->size + 1;

}

void BFS(Graph G, int s){ 
	if( G == NULL ){
		printf("Graph Error: calling BFS() on null Graph \n");
		exit(1);
	}
	int j;
	for(j = 1; j <= getOrder(G); j++){
		G->color[j] = 'w';
		G->dist[j] = INF;
		G->parent[j] = NIL;
	}
	G->source = s;
	G->color[s] = 'g';
	G->dist[s] = 0;
	G->parent[s] = NIL;
	List L = newList();
	append(L, s);
	int u;
	while(!isEmpty(L)){
		u = front(L);
		deleteFront(L);
		moveTo(G->adj[u], 0);
		//for(int x = 0; x < length( G->adj[u] ); x++){
		while(!off(G->adj[u]) ){   
			int i = getElement(G->adj[u]);  
			if (G->color[i] == 'w'){
				G->color[i] = 'g';
				G->dist[i] = G->dist[u] + 1;
				G->parent[i] = u;
				append(L, i);
			}
			movePrev(G->adj[u]);
		}
		G->color[u] = 'b';
	}
	freeList(&L);
}

/*** Other operations ***/
void printGraph(FILE* out, Graph G){ 
	if( G == NULL ){
		printf("Graph Error: calling printGraph() on null Graph \n");
		exit(1);
	}
	int i;
	fprintf(out, "Printing Graph ");
	for(i = 1; i <= getOrder(G); i++){
		fprintf(out, "%d: ", i);
		printList(out, G->adj[i]);
		fprintf(out, "\n");	
	}
}




