/* Tim Mertogul
 * 1331402
 * CMPS12B
 * 07/09/13
 * Search program that takes command line words
 * Search.java 
 */

import java.io.*;
import java.util.Scanner;

public class Search {


   public static int Search(String[] word, int[] lineNumber, int p, int r,  String target){

      int q;
      if(p == r) {
         return -1;
      }else{
         q = (p+r)/2;
         if(word[q].compareTo(target) == 0){
             return lineNumber[q];
//            return word[q] + " found at line " + lineNumber[q];
         }else if(word[q].compareTo(target) > 0){
            return Search(word, lineNumber, p, q-1, target);
         }else{ // target > word[q]
            return Search(word, lineNumber, q+1, r, target);
         }
      }
   }
   
   public static void main(String[] args) throws IOException{
      Scanner in = null;
      PrintWriter out = null;
      String line = null;
      int n;
      if(args.length < 2){
         System.out.println("Usage: Search file target1 [target2 ..]"); 
         System.exit(1);
      }
      in = new Scanner(new File(args[0]));

      String[] target = new String[args.length];

      int lineCount = 0;
      while( in.hasNextLine() ){
         in.nextLine();
         lineCount++;
      }
      int[] lineNumber = new int[lineCount];      
      String[] token = null;
      int LC, WL, LN = 0;
      String[] word = new String[lineCount];
      in = new Scanner(new File(args[0]));      
      in.useDelimiter("\n");
      while( in.hasNext() ){
         word[LN] = in.next(); 
         lineNumber[LN] = (LN+1);
         LN++;
      }
      in.close();
      mergeSort(word, lineNumber, 0, lineCount-1);

      int t = 1;
      int q = -1;
      while( t < args.length ){
         target[t] = args[t];
         q = Search(word, lineNumber, 0, lineCount, target[t]);
         if(q != -1) {
            System.out.println(target[t] + " found on line " + q);
         } else { System.out.println(target[t] + " not found"); }
         t++;
      }

   }

   public static void mergeSort(String[] word, int[] lineNumber, int p, int r){
      int q;
      if(p < r) {
         q = (p+r)/2;
         mergeSort(word, lineNumber, p, q);
         mergeSort(word, lineNumber, q+1, r);
         merge(word, lineNumber, p, q, r);
      }
   }

   public static void merge(String[] word, int[] lineNumber, int p, int q, int r){
      int n1 = q-p+1;
      int n2 = r-q;
      String[] L = new String[n1];
      int[] Li = new int[n1];
      String[] R = new String[n2];
      int[] Ri = new int[n2];
      int i, j, k;

      for(i=0; i<n1; i++){
         L[i] = word[p+i];
         Li[i] = lineNumber[p+i];
      }
      for(j=0; j<n2; j++){
         R[j] = word[q+j+1];
         Ri[j] = lineNumber[q+j+1];
      }
      i = 0; j = 0;
      for(k=p; k<=r; k++){
         if( i<n1 && j<n2 ){
            if( L[i].compareTo(R[j]) < 0 ){
               word[k] = L[i];
               lineNumber[k] = Li[i];
               i++;
            }else{
               word[k] = R[j];
               lineNumber[k] = Ri[j];
               j++;
            }
         }else if( i<n1 ){
            word[k] = L[i];
            lineNumber[k] = Li[i];
            i++;
         }else{ // j<n2
            word[k] = R[j];
            lineNumber[k] = Ri[j];
            j++;
         }
      }
   }
}

