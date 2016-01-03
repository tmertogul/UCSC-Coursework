/*
# Tim Mertogul
# 1331402
# CMPS12B
# 08/16/13
# Dictionary ADT program that implements methods using hash tables
# Dictionary.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Dictionary.h"

#define MAX_LEN 180	

const int tableSize=101; // or some prime other than 101


typedef struct NodeObj {
    int count;
    char* key;
    char* value;
    struct NodeObj *next;
} NodeObj;

typedef NodeObj* Node;

Node newNode(char* k, char* v) {
   Node N = malloc(sizeof(NodeObj));
   assert(N!=NULL);
   N->key = k;
   N->value = v;
   N->next = NULL;
   return(N);
}

void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

typedef struct DictionaryObj{
    int items;
    int size;
    int numItems;
    //char line[MAX_LEN];
    char table[MAX_LEN];
    struct Node* head;
    //char* table[MAX_LEN];
    //    while( fgets(table, MAX_LEN, in)!=NULL ){
//       lineCount++;
//       frequency[hash(table)]++;
//    }

    //Node* table;
} DictionaryObj;

//typedef struct DictionaryObj* Dictionary;

// rotate_left()
// rotate the bits in an unsigned int
unsigned int rotate_left(unsigned int value, int shift) {
        int sizeInBits = 8*sizeof(unsigned int);
        shift = shift & (sizeInBits - 1);
        if ( shift == 0 )
return value;
return (value << shift) | (value >> (sizeInBits - shift));
}
     // pre_hash()
     // turn a string into an unsigned int
     unsigned int pre_hash(char* input) {
        unsigned int result = 0xBAE86554;
        while (*input) {
           result ^= *input++;
           result = rotate_left(result, 5);
        }
        return result;
     }
// hash()
// turns a string into an int in the range 0 to tableSize-1 
     int hash(char* key){
        return pre_hash(key)%tableSize;
     }

/* Hash table ADT functions 

list *insert_word( list *word_list, char *word, int *used);
//void insert(Dictionary D, char* k, char* v);

void destroy(list *word_list);
//void delete(Dictionary D, char* k);

list *search_list( list *word_list, char *word, int *count);
char* lookup(Dictionary D, char* k);

unsigned int hash(char *word, int tbl_size);
list *search_table( table *hash_table, char *word, int *count);
table *grow_table(table *hash_table);

list *create_node( char *word);
void *gcalloc( int number, int size);
*/


// public functions ----------------------------------------------------
Dictionary newDictionary(){
   Dictionary D = malloc(sizeof(DictionaryObj));
   assert(D!=NULL);
   //D->table = calloc(tableSize, sizeof(NodeObj));
   //D->root = NULL;
   //D->table;
   D->size = 0;
   D->numItems = 0;
   return D;
}

void freeDictionary(Dictionary* pD){
   if( pD!=NULL && *pD!=NULL ){
      makeEmpty(*pD);
      free(*pD);
      *pD = NULL;
   }
}

int isEmpty(Dictionary D){
   if( D==NULL ){
      fprintf(stderr, 
         "calling isEmpty() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }
   return(D->numItems==0);
}

int size(Dictionary D){
   if( D==NULL ){
      fprintf(stderr, 
         "calling size() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }
   return(D->numItems);
}

char* lookup(Dictionary D, char* k){
   /*Node N;
   if( D==NULL ){
      fprintf(stderr, 
         "calling lookup() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }
   N = findKey(D->root, k);
   return ( N==NULL ? NULL : N->value );*/
   return "lookup not complete";
}

void insert(Dictionary D, char* k, char* v){
	int hashkey;
	int table[tableSize];
	int i;
	int sz;
	sz = size(D);
	//int lineCount = 0;
	if(sz==0){
	   for(i=0; i<tableSize; i++){
	      table[i] = 0;
	   }
	}
	hashkey = hash(k);
	//Node toInsert = newNode(k, v);
	fprintf(stderr, "%s %s\n", k, v);
	//D->table[hashkey] = toInsert;
	

	//printf(line);
	
   /*Node N, A, B;
   if( D==NULL ){
      fprintf(stderr, 
         "Dictionary Error: calling insert() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }
   if( findKey(D->root, k)!=NULL ){
      fprintf(stderr, 
         "Dictionary Error: cannot insert() duplicate key: \"%s\"\n", k);
      exit(EXIT_FAILURE);
   }
   N = newNode(k, v);
   B = NULL;
   A = D->root;
   while( A!=NULL ){
      B = A;
      if( strcmp(k, A->key)<0 ) A = A->left;
      else A = A->right;
   }
   if( B==NULL ) D->root = N;
   else if( strcmp(k, B->key)<0 ) B->left = N;
   else B->right = N;
   D->numItems++;*/
}

void delete(Dictionary D, char* k){
   /*Node N, P, S;
   if( D==NULL ){
      fprintf(stderr, 
         "Dictionary Error: calling delete() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }
   N = findKey(D->root, k);
   if( N==NULL ){
      fprintf(stderr, 
         "Dictionary Error: cannot delete() non-existent key: \"%s\"\n", k);
      exit(EXIT_FAILURE);
   }
   if( N->left==NULL && N->right==NULL ){
      if( N==D->root ){
         D->root = NULL;
         freeNode(&N);
      }else{
         P = findParent(N, D->root);
         if( P->right==N ) P->right = NULL;
         else P->left = NULL;
         freeNode(&N);
      }
   }else if( N->right==NULL ){
      if( N==D->root ){
         D->root = N->left;
         freeNode(&N);
      }else{
         P = findParent(N, D->root);
         if( P->right==N ) P->right = N->left;
         else P->left = N->left;
         freeNode(&N);
      }
   }else if( N->left==NULL ){
      if( N==D->root ){
         D->root = N->right;
         freeNode(&N);
      }else{
         P = findParent(N, D->root);
         if( P->right==N ) P->right = N->right;
         else P->left = N->right;
         freeNode(&N);
      }
   }else{  // N->left!=NULL && N->right!=NULL
      S = findLeftmost(N->right);
      N->key = S->key;
      N->value = S->value;
      P = findParent(S, N);
      if( P->right==S ) P->right = S->right;
      else P->left = S->right;
      freeNode(&S);
   }
   D->numItems--;*/
}

void makeEmpty(Dictionary D){
   /*deleteAll(D->root);
   D->root = NULL;
   D->numItems = 0;*/
}

/*void printInOrder(FILE* out, Node R){
   if( R!=NULL ){
      //printInOrder(out, R->left);
      fprintf(stderr, "%s %s\n", R->key, R->value);
      //printInOrder(out, R->right);
   }
}*/

void printDictionary(FILE* out, Dictionary D){
   if( D==NULL ){
      fprintf(stderr, 
         "calling printDictionary() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }
   //printInOrder(out, D->list);
   /*
   void printDictionary(htable h, FILE *stream) {
       int i;
       for(i = 0; i < h->capacity; i++) {
          if(h->key[i] != NULL) {
             fprintf(stream, "%d%s\n", h->frequencies[i], h->key[i]);
          }
       }

   */
}

//==============listADTfunctions================










