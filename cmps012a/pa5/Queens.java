/*
 * Queens.java
 * Tim Mertogul
 * 1331402
 * pa5
 * Program that finds all solutions to the n-Queens problem
 */

import java.util.*;


class Queens{

   public static void main(String[] args ){
      Scanner sc = new Scanner(System.in);      
      int n=0, ns=0, i;
      String verbose = "-v";

      if(args.length==0){
         stderr(0);
      }
      if(args.length == 2){
         if(verbose.equals(args[0])){
            try{
               n = Integer.parseInt(args[1]);
            }
            catch (NumberFormatException e) {
               stderr(0);
            }      
         }
         else {
            stderr(0);
         }
      } 
      if(args.length == 1){
         try{
            n = Integer.parseInt(args[0]);
         }
         catch (NumberFormatException e) {
            stderr(0);
         }
      }
      else if(args.length >= 3){
         stderr(0);
      }
      int[] list = new int[n+1];
      makeArray(list); 
      for(i=1; i<=factorial(n); i++){
         if(isSolution(list)){
            ns++;
            if(verbose.equals(args[0])){
               printArray(list);
            }
         } 
         nextPermutation(list);
      }
      boolean solutions = false;
      
      System.out.println(n+"-Queens has "+ns+" solutions");
   
   } 
   static void stderr(int a){
      System.out.println("Usage: Queens [-v] number");
      System.out.println("Option: -v verbose output, print all solutions");
      System.exit(0);
   }   
   static void makeArray(int[] A){
      int i, n;

      for(i=1; i<A.length; i++){
         A[i] = i;
      }
   }
   static void printArray(int [] A){
      int i;

      for(i=1; i<A.length; i++){
         if(i == 1){
            System.out.print("("+A[i]+", ");
         }
         else if( i != A.length-1){
            System.out.print(A[i]+", ");
         }
         else{
            System.out.print(A[i]+")");
         }
      }
      System.out.println("");
   }
   static void swap(int[] A, int i, int j){
      int n=A.length, t;
      if(i>=0 && j>=0 && i<n && j<n){
         t = A[i];
         A[i] = A[j];
         A[j] = t;
         i++;
         j--;
      }
      return;
   }
   static void nextPermutation(int[] A){
      int pivot = 0, successor = 0, end=0;
      int j=A.length-1;
      for(int i=A.length-2; i>=0 && end==0; i--){
         if(A[i] < A[j]){
            pivot = i;
            end = 1;
         }
      j--;
      }
      if(end == 0){
         reverse(A, 0, A.length-1);
      }
      for(int i=A.length-1; i>=0 && successor == 0; i--){
         if(A[i] > A[pivot]){
            successor = i;
         }
      }
      swap(A, pivot, successor);
      reverse(A, pivot+1, A.length-1);
   }
   static boolean isSolution(int[] A){
      boolean positive = true;
      int H, D, a;
      for(int i=1; i<=A.length-1; i++){
         for(int j = i+1; j<=A.length-1; j++){
            H = Math.abs(A[i] - A[j]);
            D = Math.abs(i - j);
            if(H == D){
               positive = false;
            }
         }
      }         
   return positive;
   }
   static void reverse(int[] A, int i, int j){
      while(i<j) {
         swap(A,i,j);
         i++;
         j--;
      }
   }
   static int factorial(int n){
      int f = 1, i = 1;
         while(i<=n){
            f *=i;
            i++;
         }
      return f;
   }
}
