/*
Tim Mertogul
1331402
tmertogu
CMPS101 Summer 2014
08/11/14
PA5
List.h
List ADT header file
*/

//-----------------------------------------------------------------------------
// List.h
// Header file for List ADT
//-----------------------------------------------------------------------------

#ifndef _List_H_INCLUDE_
#define _List_H_INCLUDE_


// Exported type --------------------------------------------------------------
typedef struct ListObj* List;


// Constructors-Destructors ---------------------------------------------------

// newList()
// Returns reference to new empty List object. 
List newList();

// freeList()
// Frees all heap memory associated with List *pL, and sets *pL to NULL.
void freeList(List* pL);



// Access functions -----------------------------------------------------------

// front()
// Returns the value at the front of L.
// Pre: !isEmpty(L)
int front(List L);

// length()
// Returns the length of L.
int length(List L);

// isEmpty()
// Returns true (1) if L is empty, otherwise returns false (0)
int isEmpty(List L);


int getIndex(List L);
int back(List L);
int getElement(List L);
//int equals(List A, List B);



// Manipulation procedures ----------------------------------------------------

// append()
// Places new data element at the end of L
void append(List L, int data);

void prepend(List L, int data);


// deleteFront()
// Deletes element at front of L
// Pre: !isEmpty(L)
void deleteFront(List L);

void deleteBack(List L);

void clear(List L);
void moveTo(List L, int i);
void movePrev(List L);
void moveNext(List L);
void insertBefore(List L, int data);
void insertAfter(List L, int data);
void delete(List L);
int off(List L);




// Other operations ------------------------------------------------------------

// printList()
// Prints data elements in L on a single line to stdout.
//void printList(List L);

// Prints data elements in L on a single line to fileout.
void printList(FILE* out, List L);


// equals()
// returns true (1) if A is identical to B, false (0) otherwise
int equals(List A, List B);

List copyList(List L);

#endif
