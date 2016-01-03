//-----------------------------------------------------------------------------
// IntegerQueue.java
// Array based implementation of IntegerQueue ADT (with array doubling)
//-----------------------------------------------------------------------------

public class Queue { //implements QueueInterface{

   private class Node {
      Object top;
      Node next;

      Node(Object top){
         this.top = top;
         this.next = next;
      }
   }

   //private static final int INITIAL_SIZE = 1;
   //private int physicalSize;  // current length of underlying array
   //private int[] item;        // array of IntegerQueue items
   private int numItems;      // number of items in this IntegerQueue
   private int front;         // index of front element
   private int back;          // index of back element
   private Node head;
   private Node top;

/*   // doubleItemArray()
   // doubles the physical size of the underlying array item[]
   private void doubleItemArray(){
      int[] newArray = new int[2*physicalSize];
      for(int i=0; i<numItems; i++) newArray[i] = item[(front+i)%physicalSize];
      item = newArray;
      physicalSize *=2;
      front = 0;
      back = numItems-1;
   }
*/
   // IntegerQueue()
   // default constructor for the IntegerQueue class
   public Queue(){
      //physicalSize = INITIAL_SIZE;
      //item = new int[physicalSize];
      top = null;
      numItems = 0;
      //back = -1;
   }

   // isEmpty()
   // pre: none
   // post: returns true if this IntgerQueue is empty, false otherwise
   public boolean isEmpty(){
      //System.out.println("Queue is now empty");
      return(numItems == 0);
   }


   public int length(){
      return numItems;
   }

   // enqueue()
   // adds x to back of this IntegerQueue
   // pre: none
   // post: !isEmpty()
   public void enqueue(Object newItem){

      Node insrt = new Node(newItem);
      if(top == null){
         top = insrt;
      }
      else{
         int en=0;
         Node back = top;
         //Node temp = top;
         while(en<numItems-1){
            back = back.next;
            en++;
         }
         back.next = insrt;
         //temp.next = top;
         //top = temp;
      }

//      if( numItems == physicalSize ) doubleItemArray();
      numItems++;
//      back = (back+1)%physicalSize;
//      item[back] = x;
   }

   private Node prev(){
      Node back = null;
      Node temp = top;
      int i=1;
      while(i <= numItems-1 ){
         back = temp;
         temp = temp.next;
         i++;
      }
      return back;
   }

   public Object dequeue() throws QueueEmptyException{
	 int i = 0;
	      if( prev()==null ){
	         throw new QueueEmptyException("cannot dequeue() empty queue");
	      }
	      else{

	         //while(en<numItems-1){
	            top = top.next;
	           // en++;
	        // }
	       //  Node temp = prev();
	       //  temp.next = null;
	         //top = temp;
	         numItems--;
	         return top;
	      }
	   }

	   // peek()
	   // pre: !isEmpty()
	   // post: returns item at front of Queue
	   public Object peek() throws QueueEmptyException{
	      Node peek = top;
	      if( numItems==0 ){
	         throw new QueueEmptyException("cannot peek() empty queue");
	      }
	      //System.out.println(peek.top);
	      return peek.top;
	   }

	   public void dequeueAll() throws QueueEmptyException{
	      if( numItems==0 ){
	         throw new QueueEmptyException("cannot dequeueAll() empty queue");
	      }
	      else{
	         numItems = 0;
	         top = null;
	      }
	   }

	   // toString()
	   // overrides Object's toString() method
	   public String toString(){
	      String s = "";
	/*      for(int i=0; i<numItems; i++){
	         s += item[(front+i)%physicalSize] + " ";
	      }
	*/
	      for(Node N=top; N!=null; N=N.next){
	        s += N.top + " ";
	    }

	      return s;

	   }
	}