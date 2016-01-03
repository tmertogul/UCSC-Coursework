/*Tim Mertogul
* 1331402
* CMPS101 Summer14
* 07/09/14
* List ADT in C
* List.c
*/

#include<stdio.h>
#include<stdlib.h>
#include "List.h"


// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj{
   int data;
	int index;
   struct NodeObj* next;
   struct NodeObj* prev;
   struct NodeObj* cursor;
} NodeObj;

// private Node type
typedef NodeObj* Node;

// private ListObj type
typedef struct ListObj{
   Node front;
   Node back;
   Node cursor;
   int length;
   int index;
} ListObj;


// Constructors-Destructors ---------------------------------------------------

// newNode()
// Returns reference to new Node object. Initializes next and data fields.
// Private.
Node newNode(int data){
   Node N = malloc(sizeof(NodeObj));
   N->data = data;
   N->index = -1;
   N->next = NULL;
   N->prev = NULL;
   //N->index = index;
   return(N);
}

// freeNode()
// Frees heap memory pointed to by *pN, sets *pN to NULL.
// Private.
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      //free(*pN->next);
      //free(*pN->prev);
      //free(*pN->);
      *pN = NULL;
   }
}

// newList()
// Returns reference to new empty List object.
List newList(void){
   List L;
   L = malloc(sizeof(ListObj));
   L->front = L->back = NULL;
   L->length = 0;
   L->cursor = NULL;
   L->index = -1;
   return(L);
}


// freeList()
// Frees all heap memory associated with List *pL, and sets *pL to NULL.S
void freeList(List* pL){

   if(pL!=NULL && *pL!=NULL) { 
      while( length(*pL) > 0 ) { 
         deleteFront(*pL); 
      }
      //clear(*pL);
      free(*pL);
      *pL = NULL;
   }
}

// Access functions -----------------------------------------------------------

// getLength()
// Returns the length of L.
int length(List L){
   return(L->length);
}

// getIndex()
// Returns the index of L.
int getIndex(List L){
   return(L->index);
}

// getFront()
// Returns the value at the front of L.
// Pre: !isEmpty(L)
int front(List L){
   if( length(L) == 0){
	  printf("List Error: calling front() on an empty List\n");
	  exit(1);
   }
   return(L->front->data);

}

int back(List L){
   if( length(L) == 0){
	  printf("List Error: calling back() on an empty List\n");
	  exit(1);
   }
   return(L->back->data);
}

int getElement(List L){
   if( length(L) == 0){
	  printf("List Error: calling getElement() on an empty List\n");
	  exit(1);
   }
   return(L->cursor->data);
}


// isEmpty()
// Returns true (1) if L is empty, otherwise returns false (0)
/*
int isEmpty(List L){
   if( L==NULL ){
      printf("List Error: calling isEmpty() on NULL List reference\n");
      exit(1);
   }
   return(L->length==0);
}*/

// equals()
// returns true (1) if A is identical to B, false (0) otherwise
int equals(List A, List B){
   int flag = 1;
   Node N = NULL;
   Node M = NULL;

   if( A==NULL || B==NULL ){
      printf("List Error: calling equals() on NULL List reference\n");
      exit(1);
   } 
   N = A->front;
   M = B->front;
   if( A->length != B->length ) { return 0; }
   while( flag && N!=NULL){
      flag = (N->data==M->data);
      N = N->next;
      M = M->next;
   }
   return flag;
  // freeNode(&M);
 //  freeNode(&N);
}



// Manipulation procedures ----------------------------------------------------

void clear(List L){
	L->front = L->back = NULL;
	L->cursor = NULL;
	L->index = -1;
	L->length = 0;
}


void moveTo(List L, int i) {
	//Node temp = NULL;
	
	if (0 <= i && i <= L->length -1){
		//System.out.println("moving");
		L->cursor = L->front;
		L->index = 0;
			//int j = 0;
		while(getIndex(L) < i){
			moveNext(L);
				//System.out.println("getIndex = "+getIndex(L));
		}
	} else { 
		//System.out.println("nulling");
		L->cursor = NULL; 
		L->index = -1;
	}	
}

void movePrev(List L){
	//printf("initialized Z movePReV \n");

	if(L->index > L->length -1){
		//printf("first IF \n");
		L->cursor = NULL;
		L->index = -1;
	} else if (L->index == -1 || L->index == 0){
		//printf(" IF/ELSE \n");
		L->cursor = NULL;
		L->index = -1;
	} else { 
		//printf(" ELSEEEE \n");
		//printf("cursor prev = %d ", L->cursor->prev);

		//L->cursor->next = L->cursor;
		L->cursor = L->cursor->prev;
		//printf("can we make it? \n");
		//printf("index = %d \n", getIndex(L));
		L->index--;
		//printf("index = %d \n", getIndex(L));
		//printf("cursor = ");
		//printf("%d ", getElement(L));
		//printf(" \n ");
	}
}

void moveNext(List L){
	if(L->index == L->length-1){
		L->cursor = NULL;
		L->index = -1;
	} else if (L->index == -1){
		L->cursor = NULL;
	} else {
		//L->cursor->prev = L->cursor;
		L->cursor = L->cursor->next;
		L->index++;
	}
}

void prepend(List L, int data) {
	Node newF = newNode(data);
	if(length(L) ==0){ 
		L->back = newF;
	}
	else { 
		L->front->prev = newF;
		newF->next = L->front;
	}
	L->front = newF;
	L->length++;	
	if (getIndex(L) != -1) {
		L->index++;
	}
	freeNode(&newF);
}

void append(List L, int data) { 
	Node newB = newNode(data);
	if(length(L) ==0){ 
		L->front = newB;
	}
	else{
	    L->back->next = newB;
	    newB->prev = L->back;
	}
	L->back = newB;
	L->length++;
	freeNode(&newB);
		
}

void insertBefore(List L, int data){
	if(getIndex(L) == 0){
		prepend(L,data);
	}else if(getIndex(L) >= 0 && length(L) > 0 ){
		Node newBC = newNode(data);
		Node temp = NULL;
		temp = L->cursor->prev;
		newBC->prev = temp;
		temp->next = newBC;
		newBC->next = L->cursor;
		L->cursor->prev = newBC;
		L->length++;
		if (getIndex(L) != -1) {
			L->index++;
		}	
		freeNode(&newBC);	
	}
	else{
	}
}

void insertAfter(List L, int data){
	if(getIndex(L) == length(L)-1 ){
		append(L,data);
	}
	else{
		Node newAC = newNode(data);
		Node temp = NULL;
		temp = L->cursor->next;
		newAC->next = temp;
		temp->prev = newAC;
		newAC->prev = L->cursor;
		L->cursor->next = newAC;
		L->length++;	
		freeNode(&newAC);
	}		
}

void deleteFront(List L){
	Node TEMP = NULL;
	TEMP = L->front->next;
	L->front = TEMP;	
	L->front->prev = NULL;	
	TEMP = NULL;
	L->length--;
	
	if (getIndex(L) != -1) {
		L->index--;
	}
	freeNode(&TEMP);
}

void deleteBack(List L){  
	Node temp = NULL;
	temp = L->back->prev;
	L->back = temp;
	L->back->next = NULL;
	temp = NULL;
	L->length--;
	freeNode(&temp);
}


void delete(List L){
	Node be4;
	Node l8r;
	if(getIndex(L) == 0){
		deleteFront(L);
		L->length++;
	} else if(getIndex(L) == length(L)-1){
		deleteBack(L);
		L->length++;
	} else {
		be4 = L->cursor->prev;
		l8r = L->cursor->next;
		be4->next = l8r;	
		l8r->prev = be4;
	}
	L->cursor = NULL;
	L->length--;
	freeNode(&be4);
	freeNode(&l8r);
}  

// Other Functions ------------------------------------------------------------

// printList()
// Prints data elements in L on a single line to stdout.
void printList(FILE* out, List L){
   Node N = NULL;

   if( L==NULL ){
      fprintf(out, "List Error: calling printList() on NULL List reference\n");
      exit(1);
   }
   for(N = L->front; N != NULL; N = N->next){
      fprintf(out, "%d ", N->data);
   }
}

List copyList(List L){
	List sb = newList();
	moveTo(L,0);
	while(getIndex(L) < length(L)-1){
		append(sb,getElement(L));
		moveNext(L);
	}
	append(sb,getElement(L));
	
	L->cursor = NULL;
	sb->cursor = NULL;
	return sb;
	
}
