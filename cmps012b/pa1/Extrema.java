/*Tim Mertogul
* 1331402
* CMPS12B
* 07/03/13
* Finds the Mins and Maxs of a set of integers
* Extrema.java
*/

public class Extrema{
   
   public static void main(String[] args){
      int[] B = {-1, 2, 6, 3, 9, 2, -3, -2, 11, 5, 7};
      System.out.println( "max = " + maxArray(B, 0, B.length-1) );
      System.out.println( "min = " + minArray(B, 0, B.length-1) );
   }
 
   static int maxArray(int[] A, int p, int r){
      int q, m1 = 0, m2 = 1, max;
         if( (r == 0) || (r == p) ){
            return A[r];
         }
         if(A.length > 1){
            q = (p+r)/2;
            m1 = maxArray(A, p, q);
            m2 = maxArray(A, q+1, r);
         }    
      if(m1 > m2){ return m1; }
      else{ return m2; }
   }

   static int minArray(int[] A, int p, int r){
      int q, m1 = 0, m2 = 1, min;
         if( (r == 0) || (r == p) ){
            return A[r];
         }
         if(A.length > 1){
            q = (p+r)/2;
            m1 = minArray(A, p, q);
            m2 = minArray(A, q+1, r);
         }         
      if(m1 < m2){ return m1; }
      else{ return m2; }
   }
}
