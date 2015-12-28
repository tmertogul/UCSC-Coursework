/* Tim Mertogul
 * 1331402
 * CMPS12B
 * 08/16/13
 * Dictionary ADT program that implements methods using BST
 * Dictionary.java 
 */

//-----------------------------------------------------------------------------
// Dictionary.c
// Binary Search Tree implementation of the Dictionary ADT
//-----------------------------------------------------------------------------

public class Dictionary implements DictionaryInterface{
//public class Dictionary {

	private class Node {
   	   String key;
   	   String value;
   	   Node left;
   	   Node right;
 
   	   Node(String key, String value){
          this.key = key;
       	  this.value = value;
       	  this.left = left;
       	  this.right = right;
       }
  	}

  private Node root;     // reference to first Node in List
  private Node toDelete; //how to lookup stuff to delete
  private Node tail;     // reference to last Node in List
  private int numPairs;  // number of items in this Dictionary


  public Dictionary(){
     root = null;
     toDelete = null;
     numPairs = 0;
  }

  private Node findKey(Node R, String k){
	//String.compareTo(String anotherString)
	
	 if(R==null || k.compareTo(R.key)==0){
	    return R;
	 }
	 if( k.compareTo(R.key)<0 ){
		return findKey(R.left, k);
	 }
	 else{ // strcmp(k, R->key)>0 
	    return findKey(R.right, k);
	 }
  }

  private Node findParent(Node N, Node R){
   Node P=null;
   if( N!=R ){
      P = R;
      while( P.left!=N && P.right!=N ){
         if( N.key.compareTo(P.key)<0){
            P = P.left;
         }
         else{
            P = P.right;
         }
      }
   }
   return P;
}

private Node findLeftmost(Node R){
   Node L = R;
   if( L!=null ) for( ; L.left!=null; L=L.left) ;
   return L;
}

private void deleteAll(Node N){
   if( N!=null ){
      deleteAll(N.left);
      deleteAll(N.right);
   }
}


  public boolean isEmpty(){
     return(numPairs == 0);
  }
  public int size() {
     return numPairs;
  }

  public String lookup(String key) {
     Node R = root;
     Node N;
     N = findKey(R, key);
     if(N==null){
        return null;
     }
     else{
	    toDelete = N;
        return N.value;
     }
  }
	
  public void insert(String key, String value) 
     throws KeyCollisionException{
     Node N, A, B;
     if(  lookup(key)!=null  ){
        throw new KeyNotFoundException(
        "Dictionary Error: cannot insert() duplicate key");
     }
     N = new Node(key, value);
     B = null;
     A = root;
     while( A!=null ){
      B = A;
      if( key.compareTo(A.key)<0 ) A = A.left;
      else A = A.right;
     }
     if( B==null ) root = N;
     else if( key.compareTo(B.key)<0 ) B.left = N;
     else B.right = N;
     numPairs++;
   }
    
  public void delete(String key)
     throws KeyNotFoundException{	  
	 Node N, P, S;
	 lookup(key);
	 N = toDelete;
	 if(  lookup(key)==null  ){
	        throw new KeyNotFoundException(
	        "cannot delete non-existent key");
	 }
	 if( N.left==null && N.right==null ){
	      if( N==root ){
	         root = null;
	      }else{
		     P = findParent(N, root);
		     if( P.right==N ) P.right = null;
		     else P.left = null;
		  }
	 }else if( N.right==null ){
	    if( N==root ){
	       root = N.left;
	    }else{
	       P = findParent(N, root);
	       if( P.right==N ) P.right = N.left;
	       else P.left = N.left;
	    }
	 }else if( N.left==null ){
		if( N==root ){
	       root = N.right;
	    }else{
           P = findParent(N, root);
           if( P.right==N ) P.right = N.right;
           else P.left = N.right;
        }
     }else{  // N->left!=NULL && N->right!=NULL
        S = findLeftmost(N.right);
		N.key = S.key;
	    N.value = S.value;
	    P = findParent(S, N);
	    if( P.right==S ) P.right = S.right;
        else P.left = S.right;
     }
     numPairs--;
 }
		     
  public void makeEmpty(){
     root = null;
     numPairs = 0;
  }


  // printInOrder()
  // prints the (key, value) pairs belonging to the subtree rooted at R in order
  // of increasing keys to file pointed to by out.
  private String printInOrder(Node R){
     String s = "";
     if( R!=null ){
        printInOrder(R.left);
        s += R.key + " " + R.value + " " + "\n" + printInOrder(R.left);
        printInOrder(R.right);
        s +=  printInOrder(R.right);
     }
     return s;
  }
  
  public String toString(){
    
     Node R = root;
     String s;
     s = printInOrder(R);
     return s;
  }

}

