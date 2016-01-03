/****************************************************************************************
*  ListTest.c
*  Test client for List ADT
*****************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"

int main(int argc, char* argv[]){
   
   
   FILE *out;

   out = fopen(argv[2], "w");



   List A = newList();
   List B = newList();
   List C = NULL;
   int i;

   for(i=1; i<=5; i++){
      append(A,i);
      prepend(B,i);
   }

   printList(out,A); 
   printf("\n");
   printList(stdout,B); 
   printf("\n");

   for(moveTo(A,0); getIndex(A)>=0; moveNext(A)){
      printf("%d ", getElement(A));
   }
   printf("\n");
   for(moveTo(B,length(B)-1); getIndex(B)>=0; movePrev(B)){
      printf("%d ", getElement(B));
   }
   printf("\n");

   C = copyList(A);
   printf("%s\n", equals(A,B)?"true":"false");
   printf("%s\n", equals(B,C)?"true":"false");
   printf("%s\n", equals(C,A)?"true":"false");

   printf("A's front = %d\n",    front(A));
   printf("A's back = %d\n",    back(A));
   deleteFront(A);
   deleteBack(A);
   printf("A's front = %d\n",    front(A));
   printf("A's back = %d\n",    back(A));

   moveTo(A,4);
   insertBefore(A,-1);
   moveTo(A,3);
   insertAfter(A,-2);
   moveTo(A,2);
   delete(A);
   printList(stdout,A);
   printf("\n");
   // printf("%d\n", length(A));

   clear(A);
   printf("%d\n", length(A));

   printf("entering A \n");
   freeList(&A);

   //clear(B);

   printf("A free, entering B \n");
   freeList(&B);

   //clear(C);

   printf("A/B free, entering C \n");
   freeList(&C);

   fclose(out);

   return(0);
}	 
