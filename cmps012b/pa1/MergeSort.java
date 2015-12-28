public class MergeSort {

   public static void mergeSort(int[] A, int p, int r){
      int q;
      if(p < r) {
         q = (p+r)/2;
         mergeSort(A, p, q);
         mergeSort(A, q+1, r);
         merge(A, p, q, r);
      }
   }

   public static void merge(int[] A, int p, int q, int r){
      int n1 = q-p+1;
      int n2 = r-q;
      int[] L = new int[n1];
      int[] R = new int[n2];
      int i, j, k;

      for(i=0; i<n1; i++) L[i] = A[p+i];
      for(j=0; j<n2; j++) R[j] = A[q+j+1];
      i = 0; j = 0;
      for(k=p; k<=r; k++){
         if( i<n1 && j<n2 ){
            if( L[i]<R[j] ){
               A[k] = L[i];
               i++;
            }else{
               A[k] = R[j];
               j++;
            }
         }else if( i<n1 ){
            A[k] = L[i];
            i++;
         }else{ // j<n2
            A[k] = R[j];
            j++;
         }
      }
   }

   public static void main(String[] args) {

      int[] B = {9,8,7,6,5,4,3,2,1};

      mergeSort(B, 0, 8);
      for(int i=0; i<9; i++) System.out.print(B[i]+" ");
      System.out.println();
   }
}


