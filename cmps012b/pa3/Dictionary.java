/* Tim Mertogul
 * 1331402
 * CMPS12B
 * 07/23/13
 * Dictionary ADT program that implements methods
 * Dictionary.java 
 */

public class Dictionary implements DictionaryInterface{

  private class Node {
     String key;
     String value;
     Node next;
     Node prev;
     Node curr;  

     Node(String key, String value){
        this.key = key;
        this.value = value;
        this.next = next;
        this.curr = curr;
        this.prev = prev;
     }
  }
  
  private Node head;     // reference to first Node in List
  private Node tail;     // reference to last Node in List
  private Node curr;     // reference to current Node in List
  private int numKeys;  // number of items in this Dictionary
  
  public Dictionary(){
     head = null;
     numKeys = 0;
  }

  private Node prev(String key){
     Node P = null;
     Node N = head;
     int i=1;
     while(i <= numKeys ){
        if( N.key == key){
           if(i==1){
              return null;
           }
           else{
              return P; 
           }
        }
        else if(N.key != key){
           P = N;
           N = N.next;
           i++;
        }
     }  
     return null;
  }


  private Node findKey(String key){
     Node N = head;
     int i=1;
     while(i <= numKeys ){
        if( N.key == key ){
           return N;
        }
        else if(N.key != key){
           N = N.next;
           i++;
        }
     }
     return null;
  }
    
  public boolean isEmpty(){
     return(numKeys == 0);
  }
  public int size() {
     return numKeys;
  }
  public String lookup(String key) {
  
     Node N = findKey(key);
     if(N==null){
        return null;
     }
     else{
        return N.value;
     }
  }
  
  public void insert(String key, String value) 
     throws KeyCollisionException{

     
     if( lookup(key)!=null ){
        throw new KeyCollisionException(
           "cannot insert duplicate keys");
     }
     else{
        if(numKeys==0){ 
           head = new Node(key, value);
           Node F = head;
           Node B = F.next;
        }
        else if(numKeys==1){
           Node N = new Node(key, value);
           N.next = head.next;
           head.next = N;
        }else{
           Node P = null; // at this point key >= 2
           Node C = head.next;
           for(int in=1; in<numKeys; in++){
              P = C;
              C = C.next;
           }
           P.next = new Node(key, value);
           P = P.next;
           P.next = C;
        }
        numKeys++;
     }
  }
  
  public void delete(String key)
     throws KeyNotFoundException{
     if(  lookup(key)==null  ){
        throw new KeyNotFoundException(
        "cannot delete non-existent key");
     }
     if(prev(key)==null){
        Node P = head;
        head = head.next;
     }
     else if(numKeys==1){
        Node N = head;
        head = head.next;
        N.next = null;
     }else{
        Node P = prev(key);
        Node N = P.next;
        P.next = N.next;
        N.next = null;
     }
     numKeys--;
     //System.out.println("Key = " + T.key);
     //System.out.println("Value = " + T.value);
     
  }
  
  public void makeEmpty(){
     head = null;
     numKeys = 0;
  }
  
  public String toString(){
     String s = "";
     for(Node N=head; N!=null; N=N.next){
        s += N.key + " " + N.value + "\n";
     }
     return s;
  }
  
}



