/*
Tim Mertogul
1331402
tmertogu
CMPS101 Summer 2014
08/11/14
PA5
List.c
List ADT
*/

#include<stdio.h>
#include<stdlib.h>
#include "List.h"


// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj{
   int data;
	//int index;
   struct NodeObj* next;
   struct NodeObj* prev;
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
   Node N = malloc(sizeof(Node));
   N->data = data;
   N->next = NULL;
   N->prev = NULL;
   return(N);
}

// freeNode()
// Frees heap memory pointed to by *pN, sets *pN to NULL.
// Private.
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

// newList()
// Returns reference to new empty List object.
List newList(void){
   List L = malloc(sizeof(ListObj));
   L->front = L->back = NULL;
   L->length = 0;
   L->cursor = NULL;
   L->index = -1;
   return(L);
}


// freeList()
// Frees all heap memory associated with List *pL, and sets *pL to NULL.S
void freeList(List* pL){
	if(pL!=NULL || *pL!=NULL) { 
		return;
	}
	while( !isEmpty(*pL) ) { 
		deleteFront(*pL); 
	}
	free(*pL);
	*pL = NULL;
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
    if( off(L) ) {
        L->index = -1;
    }
    if( isEmpty(L) ){ 
        L->index = -1;
    }
   return(L->index);
}

//returns front element in this list Pre: lengh()>0
int front(List L){
	if( L == NULL ){
		printf("List Error: called front() on null List\n");
		exit(1);	
    }
   if( isEmpty(L) ){
	  printf("List Error: calling front() on an empty List\n");
	  exit(1);
   }
   return(L->front->data);

}

//returns back element in this list Pre: lengh()>0
int back(List L){
	if( L == NULL ){
		printf("List Error: called back() on null List\n");
		exit(1);	
    }
   if( isEmpty(L) ){
	  printf("List Error: calling back() on an empty List\n");
	  exit(1);
   }
   return(L->back->data);
}

//returns cursor element in this list Pre: lengh()>0, getIndex()>=0
int getElement(List L){
	if( L == NULL ){
		printf("List Error: called getElement() on null List\n");
		exit(1);	
    }
   if( isEmpty(L) ){
      printf("List Error: calling getElement() on an empty List\n");
      exit(1);
   }
   return(L->cursor->data);
}


// isEmpty()
int isEmpty(List L){
    if( L == NULL ){
        exit(1);
    }
    return(L->length==0);
}

//Returns true if this List and L are the same integer sequence. The cursor is ignored in both lists
int equals(List A, List B){
   int flag = 1;
   Node N = NULL;
   Node M = NULL;

   if( A==NULL || B==NULL ){
      printf("List Error: calling equals() on NULL List\n");
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
}


// Manipulation procedures ----------------------------------------------------

// Re-sets this List to the empty state.
void clear(List L){
	Node temp;
	while( L->front != NULL ){
		temp = L->front;
		L->front = L->front->prev;
		freeNode(&temp);
	}
	L->index = -1;
	L->length = 0;
}

// If 0<=i<=length()-1, moves the cursor to the element at index i, otherwise the cursor becomes undefined.
void moveTo(List L, int i) {
	
	if (0 <= i && i <= L->length -1){
		L->cursor = L->front;
		L->index = 0;
		for(int j = 0; j < i; j++){
			L->cursor = L->cursor->prev;
			L->index++;
		}

	} else { 
		//System.out.println("nulling");
		L->cursor = NULL; 
		L->index = -1;
	}	
}

// If 0<getIndex()<=length()-1, moves the cursor one step toward the front of the list. If getIndex()==0, cursor becomes undefined.  If getIndex()==-1, cursor remains undefined. 
void movePrev(List L){

	if(L->index > L->length -1){
		L->cursor = NULL;
		L->index = -1;
	} else if (L->index == -1 || L->index == 0){
		L->cursor = NULL;
		L->index = -1;
	} else { 
		L->cursor = L->cursor->prev;
		L->index--;
	}
}

// If 0<=getIndex()<length()-1, moves the cursor one step toward the back of the list. If getIndex()==length()-1, cursor becomes undefined. If index==-1, cursor remains undefined.
void moveNext(List L){
	if(L->index == L->length-1){
		L->cursor = NULL;
		L->index = -1;
	} else if (L->index == -1){
		L->cursor = NULL;
	} else {
		L->cursor = L->cursor->next;
		L->index++;
	}
}

// Inserts new element before front element in this List.
void prepend(List L, int data) {
	Node newF = newNode(data);
	if(isEmpty(L)){ 
		L->front = L->back = newF;
	}
	else { 
		newF->next = L->front;
		L->front->prev = newF;
		L->front = newF;
	}
	L->length++;	
	if (getIndex(L) != -1) {
		L->index++;
	}
	//freeNode(&newF);
}

// Inserts new element after back element in this List.
void append(List L, int data) { 
	Node newB = newNode(data);
	if(isEmpty(L)){ 
		//printf("empty, adding %d\n", data);
		L->front = L->back = newB;
	}
	else{
		//printf("appending %d\n", data);
		newB->prev = L->back;
		L->back->next = newB;
		L->back = newB;
	}
	L->length++;
	//freeNode(&newB);
	//printf("appended %d\n", data);
}


// Inserts new element before cursor element in this List. Pre: length()>0, getIndex()>=0
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

// Inserts new element after cursor element in this List. Pre: length()>0, getIndex()>=0
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


// Deletes the front element in this List. Pre: length()>0
void deleteFront(List L){
	Node temp = NULL;
	temp = L->front->next;
	L->front = temp;	
	L->front->prev = NULL;	
	temp = NULL;
	L->length--;
	
	if (getIndex(L) != -1) {
		L->index--;
	}
	freeNode(&temp);
}

// Deletes the back element in this List. Pre: length()>0
void deleteBack(List L){  
	Node temp = NULL;
	temp = L->back->prev;
	L->back = temp;
	L->back->next = NULL;
	temp = NULL;
	L->length--;
	freeNode(&temp);
}

//Deletes cursor element in this List. Cursor is undefined. Pre: length()>0, getIndex()>=0
void delete(List L){
	Node be4;
	Node l8r;
	//System.out.println("length ="+length());
	if(getIndex(L) == 0){
		deleteFront(L);
		L->length++;
		//front = front.next;
	} else if(getIndex(L) == length(L)-1){
		//System.out.println("deleting back =");
		deleteBack(L);
		L->length++;
		//back = back.prev;
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

int off(List L){
	if( L->cursor == NULL ){
		return(1);
	}
	else return(0);
} 

// Other Functions ------------------------------------------------------------

// printList()
// Prints data elements in L on a single line to stdout.
void printList(FILE* out, List L){
   if( L==NULL ){
      fprintf(out, "List Error: calling printList() on NULL List reference\n");
      exit(1);
   }
   NodeObj* N = NULL;
   for(N = L->front; N != NULL; N = N->next){
      fprintf(out, "%d ", N->data);
   }
}


List copyList(List L){
	List sb = newList();
	//printf("moving to 0 \n");
	moveTo(L,0);
	//printf("MOVED to 0 \n");
	while(getIndex(L) < length(L)-1){
		append(sb,getElement(L));
		moveNext(L);
	}
	if(length(sb) != 0){
		append(sb,getElement(L));
	}
	L->cursor = NULL;
	sb->cursor = NULL;
	return sb;
	
}







