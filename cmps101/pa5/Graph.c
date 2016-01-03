/*
Tim Mertogul
1331402
tmertogu
CMPS101 Summer 2014
08/11/14
PA5
Graph.c
Graph ADT
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Graph.h"

typedef struct GraphObj{
		int Vertices; 
		int Edges; 
		char* Color; 
		int* Discover; 
		int* Parent; 
		int* Finish; 
		List* adj; 
} GraphObj;
	
Graph newGraph(int n){
	Graph G = malloc(sizeof(GraphObj));
	G->Vertices = n;
	G->Edges = UNDEF;
	G->Color = calloc(n+1, sizeof(char));
	G->Discover = calloc(n+1, sizeof(int));  
	G->Parent = calloc(n+1, sizeof(int));
	G->Finish = calloc(n+1, sizeof(int));
	G->adj = calloc(n+1, sizeof(List));
	int i;
	for(i = 1; i <= n; i++){
		G->Color[i] = 'w';
		G->Discover[i] = UNDEF;
		G->Parent[i] = NIL;
		G->Finish[i] = UNDEF;
		G->adj[i] = newList();
	}
	G->Edges = G->Edges+1;
return G; 
}

void freeGraph(Graph* pG){
	if( pG!=NULL && *pG!=NULL ){
		int i;
		for(i = 0; i < (*pG)->Vertices; i++){
			if((*pG)->adj[i] != NULL){
				freeList(&((*pG)->adj[i]));
			}
		}
	}
	free((*pG)->Color);
	free((*pG)->Discover);
	free((*pG)->Parent);
	free((*pG)->Finish);
	*pG = NULL;
} 


/* Access functions */
int getOrder(Graph G){  
	if( G == NULL ){
		printf("Graph Error: calling getOrder() on null Graph \n");
		exit(1);
	}
	return(G->Vertices);
}

int getSize(Graph G){ 
	if( G == NULL ){
		printf("Graph Error: calling getSize() on null Graph \n");
		exit(1);
	}
	return G->Edges;
}

int getParent(Graph G, int u){ /* Pre: 1<=u<=n=getOrder(G) */  
	int n = getOrder(G);
	if (1<=u && u<=n){
		return G->Parent[u];
	}
	else{
		printf("Graph Error: calling getParent() on null Graph \n");
		exit(1);
	}
}

int getDiscover(Graph G, int u){ /* Pre: 1<=u<=n=getOrder(G) */ 
	int n = getOrder(G);
	if (1<=u && u<=n){
		return G->Discover[u];
	}
	else{
		printf("Graph Error: calling getDiscover() on null Graph \n");
		exit(1);
	}
}

int getFinish(Graph G, int u){ /* Pre: 1<=u<=n=getOrder(G) */
	int n = getOrder(G);
	if (1<=u && u<=n){
		return G->Finish[u];
	}
	else{
		printf("Graph Error: calling getFinish() on null Graph \n");
		exit(1);
	}
}

/* Manipulation procedures */
void addArc(Graph G, int u, int v){ /* Pre: 1<=u<=n, 1<=v<=n */ 
	int n = getOrder(G);
	if (1<=u && u<=n && 1<=v && v<=n){
		G->Parent[v] = u;
		append(G->adj[u], v);			
		G->Edges++;
		//G->Edges = G->Edges + 1;
	}
	else{
		printf("Graph Error: calling addArc() on invalid reference \n");
		exit(1);
	}
}

void addEdge(Graph G, int u, int v){ /* Pre: 1<=u<=n, 1<=v<=n */ 
	int n = getOrder(G);
	if (1<=u && u<=n && 1<=v && v<=n){
		G->Parent[v] = u;
		append(G->adj[u], v);			
		append(G->adj[v], u);			
		G->Edges++;
		//G->Edges = G->Edges + 1;
	}
	else{
		printf("Graph Error: calling addEdge() on invalid reference \n");
		exit(1);
	}
} 

/* Other Functions */
Graph transpose(Graph G) {
	Graph T = newGraph(getOrder(G));
	for (int i=1; i<= getOrder(T); i++) {
		moveTo(G->adj[i], 0);
		//while(!off(G->adj[i])){
		while( getIndex(G->adj[i]) != -1 ){
			addArc(T, getElement(G->adj[i]), i);
			moveNext(G->adj[i]);
		}
	}
	return T;
}


Graph copyGraph(Graph G) {
	Graph C = newGraph(getOrder(G));
	for (int i=1; i<= getOrder(C); i++) {
		moveTo(G->adj[i], 0);
		//while(!off(G->adj[i])){
		while( getIndex(G->adj[i]) != -1 ){
			addArc(C, i, getElement(G->adj[i]));
			moveNext(G->adj[i]);
		}
	}
	return C;
}


/*
Graph copyGraph(Graph G){
	Graph C = newGraph(getOrder(G));
	for (int i=1; i<= getOrder(C); i++) {
		moveTo(G->adj[i], 0);
		//printf("moved to %d \n", i);
		int t = 1;
		while( length(G->adj[t]) != 0 ){
			//printf("copying %d \n", t);
			C->adj[t] = copyList(G->adj[t]);
			//printf("COPIED %d \n", t);
			t++;		
		}
		//moveNext(G->adj[i]);
	}
	return C;
}*/

void printGraph(FILE* out, Graph G){ 
	if( G == NULL ){
		printf("Graph Error: calling printGraph() on null Graph \n");
		exit(1);
	}
	int i;
	for(i = 1; i <= getOrder(G); i++){
		fprintf(out, "%d: ", i);
		printList(out, G->adj[i]);
		fprintf(out, "\n"); 
	}
}



/************************************************************************/

void DFS(Graph G, List S){ /* Pre: getLength(S)==getOrder(G) */
	if( length(S) != getOrder(G) ){
		printf("Graph Error: calling DFS() on invalid Graph and List \n");
		exit(1);
	}
	List T = copyList(S);
	clear(S);
	for(int i=1; i <= getOrder(G); i++){  		 /// for each vertex u 2 G:V
		G->Color[i] = 'w';						/// u:color D WHITE
		G->Parent[i] = NIL;						/// u:pi D NIL
	}
	int timeDFS = 0; 							// time = 0
	moveTo(T,0);
	for(int n=1; n <= getOrder(G); n++){  		 /// for each vertex u 2 G:V
		if(G->Color[getElement(T)] == 'w') { 	 /// if u:color == WHITE
			Visit(G, getElement(T), S, &timeDFS); /// VISIT.G; u/
		}
		moveNext(T);
	}
	freeList(&T);
}

void Visit(Graph G, int u, List S, int* timeDFS){
	*timeDFS = *timeDFS + 1;					/// time = time + 1
	G->Discover[u] = *timeDFS;				/// u:d = time
	G->Color[u] = 'g';							/// u:color = GRAY
	moveTo(G->adj[u],0);
	while( getIndex(G->adj[u]) >= 0){
		int v = getElement(G->adj[u]);
		if(G->Color[v] == 'w') {
			G->Parent[v] = u;
			Visit(G, v, S, timeDFS);
		}
		moveNext(G->adj[u]);
	}
	G->Color[u] = 'b';							/// u:color = BLACK
	*timeDFS = *timeDFS + 1;					/// time = time + 1
	G->Finish[u] = *timeDFS;					/// u:fDtime
	//append(S, u);
	prepend(S, u);
}


void strongComponent(Graph G, List S, FILE* out){
	List GSCC[getOrder(G)];
	int tim = 0;
//int k = 1;
	//int i = 1;
	//printList(stdout, S);
	//printf(" = S List \n");
	
	List Ti = copyList(S);
	clear(S);

	while (length(Ti) != 0){
		moveTo(Ti, 0);
		prepend(S, getElement(Ti));
		if(length(Ti) != 1) {
			deleteFront(Ti);
		}
		else if (length(Ti) == 1){
			clear(Ti);
		}
	}
	
	//printList(stdout, S);
	//printf(" = S List reversed\n");

		int CC;
		int numSC = 0;
		List T = newList();
		moveTo(S, 0);
		int u = getElement(S);
		while(getIndex(S) >= 0 ){
			//printf("%d = U...\n", u);
			while(CC != 1){
				moveTo(G->adj[getElement(S)], 0);
		 		while( getIndex(G->adj[getElement(S)]) >= 0 ){
					if(getElement(G->adj[getElement(S)]) == u){
						CC = 1;
					}
					//printList(stdout, G->adj[getElement(S)]);
					//printf(" = G->adj[getElement(S)]\n");
					moveNext(G->adj[getElement(S)]);     
					//movePrev(G->adj[getElement(S)]);     
				}
				//int element = getElement(S);
				//printf(" prepending: %d\n", element);
				//append(T, getElement(S));
				prepend(T, getElement(S));
				if(CC != 1){
					moveNext(S);  
					//movePrev(S);
				}
			}
			//fprintf(out, "Tally = %d: \n", tally);
			
			fprintf(out, "Component %d: ", ++numSC);
			printf("Component %d: ", numSC);
			printList(out, T);
			printList(stdout, T);
			
			GSCC[numSC] = T;
			tim++;
			//printf("tim = %d\n", tim);
			//printList(stdout, GSCC[numSC]);

			fprintf(out, "\n");
			printf("\n");
			//printList(stdout, GSCC[numSC]);
			//fprintf(out, " = GSCC[numSC]\n");
			CC = 0;
			clear(T);
			moveNext(S); 
			//movePrev(S);

			if(getIndex(S) == -1 ){
				//fprintf(out, "tally = %d: \n", tally);

				fprintf(out, "G contains %d strongly connected components\n", tim);
				printf("G contains %d strongly connected components\n", tim);
				/*printf("tim = %d\n", tim);

				while (i != tim){ 
					printf("WHILE  \n");

					printf("Component %d: ", k);
					fprintf(out, "Component %d: ", k);
					
					printList(stdout, GSCC[k]);
					printList(out, GSCC[k]);
					
					printf("\n");
					fprintf(out, "\n");

					
					freeList(&GSCC[k]);
					k++;
					i++;
				}*/

				exit(1);
			}
			if(getIndex(S) >= 0 ){
				//printf("%d = U...\n", u);
				u = getElement(S);
				//printf("%d = U!!!...\n", u);
			}
			//tally++;
			//printf("tally = %d: ", tally);

		}  	
		
		GSCC[0] = newList();
		freeList(&GSCC[0]);
		
}












































