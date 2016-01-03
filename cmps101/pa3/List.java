/*Tim Mertogul
* 1331402
* CMPS101 Summer14
* 07/02/14
* List ADT for pa3
* List.java
*/

public class List {
	
	private class Node {
		Object MatrixEntry;        //not sure what for
		//int index; 
		Node prev;
		Node next;
		Node cursor;  //current value
		
		Node(Object MatrixEntry){  //constructor
			//this.element = element;
			this.MatrixEntry = MatrixEntry;
			//this.index = index;
			this.next = next;
			this.prev = prev;
			//this.index = index;
		}
		
	}
	private Node front;     // reference to first Node in List
	private Node back;     // reference to last Node in List
 	private Node cursor;     // reference to current Node in List
 	private int length;  // length of list
	private int index;
	
	//constructor
	public List(){
	    front = back = cursor = null;
		index = -1;
	    length = 0;
	}
	
	//returns number of elements in this List
	int length() {
		return length;
	}
	
	//returns the index of the cursor element in this list or returns -1 if the cursor is undefined
	int getIndex(){
		if (cursor == null) {
			return -1;
		}
		else {
			return index;
		}
	}	
	
	//returns front element in this list Pre: lengh()>0
	Object front(){ 
		if(length() <= 0){
			throw new RuntimeException("List Error: front() called on empty List");
		} else {
			return front.MatrixEntry; 
		}
	}
	
	//returns back element in this list Pre: lengh()>0
	Object back(){ 
		if(length() <= 0){
			throw new RuntimeException("List Error: back() called on empty List");
		} else {
			return back.MatrixEntry; 
		}
	}
	
	//returns cursor element in this list Pre: lengh()>0, getIndex()>=0
	Object getElement(){
		if(length() <= 0 || getIndex() < 0){
			throw new RuntimeException("List Error: getElement() called on empty List or cursor points to null");
		} else {
			return cursor.MatrixEntry; 
		}
	}
	
	//Returns true if this List and L are the same integer sequence. The cursor is ignored in both lists
	public boolean equals(Object x){
		
		/*
		if(length() != L.length()){
			return false;
		}
		moveTo(0);
		L.moveTo(0);
		for(getIndex(); getIndex() < length()-1; moveNext()){
			if( getElement() != L.getElement()){
				return false;
			}
			L.moveNext();
			if( back() != L.back()){
				return false;
			}
		}*/
		return true;
	}
	
	// Re-sets this List to the empty state.
	void clear(){ 
		front = back = cursor = null;
		index = -1;
		length = 0;
	}
	
	// If 0<=i<=length()-1, moves the cursor to the element at index i, otherwise the cursor becomes undefined.
	void moveTo(int i) {
		Node temp = null;
		if (0 <= i && i <= length()-1){
			cursor = front;
			index = 0;
			while(getIndex() < i){
				moveNext();
			}

		} else { 
			cursor = null; 
			index = -1;
		}
	}
	
	// If 0<getIndex()<=length()-1, moves the cursor one step toward the front of the list. If getIndex()==0, cursor becomes undefined.  If getIndex()==-1, cursor remains undefined. 
	void movePrev(){
		if(getIndex() > length()-1){
			cursor = null;
			index = -1;
		} else if (getIndex() == -1 || getIndex() == 0){
			cursor = null;
			index = -1;
		} else { 
			cursor = cursor.prev;
			index--;
		}
	}
			
	// If 0<=getIndex()<length()-1, moves the cursor one step toward the back of the list. If getIndex()==length()-1, cursor becomes undefined. If index==-1, cursor remains undefined.
	void moveNext() {
		if(getIndex() == length()-1){
			cursor = null;
			index = -1;
		} else if (getIndex() == -1){
			cursor = null;
			index = -1;
		} else {
			cursor = cursor.next;
			index++;
		}
	}
	
	// Inserts new element before front element in this List.
	void prepend(Object MatrixEntry) {
		Node newF = new Node(MatrixEntry);
		//Node temp = null;
		if(length() ==0){ 
			back = newF;
		}
		else { 
			front.prev = newF;
			newF.next = front;
		}
		front = newF;
		length++;	
		if (getIndex() != -1) {
			index++;
		}
	}
	
	// Inserts new element after back element in this List.
	void append(Object MatrixEntry) { 
		Node newB = new Node(MatrixEntry);
		if(length() ==0){ 
			front = newB;
		}
		else{
		    back.next = newB;
		    newB.prev = back;
		}
		back = newB;
		length++;	
	}	
	
	// Inserts new element before cursor element in this List. Pre: length()>0, getIndex()>=0
	
	void insertBefore(Object MatrixEntry){
		if (length()<=0 || getIndex()<0) {
			throw new RuntimeException("List Error: insertBefore() called on empty List or cursor points to null");
		}
		if(getIndex() == 0){
			prepend(MatrixEntry);
		}else if(getIndex() >= 0 && length() > 0 ){
			Node newBC = new Node(MatrixEntry);
			Node temp = null;
			temp = cursor.prev;
			newBC.prev = temp;
			temp.next = newBC;
			newBC.next = cursor;
			cursor.prev = newBC;
			length++;
			if (getIndex() != -1) {
				index++;
			}		
		}	
	}
	
	// Inserts new element after cursor element in this List. Pre: length()>0, getIndex()>=0
	void insertAfter(Object MatrixEntry){
		if (length()<=0 || getIndex()<0) {
			throw new RuntimeException("List Error: insertAfter() called on empty List or cursor points to null");
		}
		if(getIndex() == length()-1 ){
			append(MatrixEntry);
		}
		else{
			Node newAC = new Node(MatrixEntry);
			Node temp = null;
			temp = cursor.next;
			newAC.next = temp;
			temp.prev = newAC;
			newAC.prev = cursor;
			cursor.next = newAC;
			length++;	
		}
	}
	
	// Deletes the front element in this List. Pre: length()>0
	void deleteFront(){
		if (length()<=0 || getIndex()<0) {
			throw new RuntimeException("List Error: deleteFront() called on empty List or cursor points to null");
		}
		Node temp;
		temp = front.next;
		front = temp;
		front.prev = null;
		temp = null;
		length--;
		if (getIndex() != -1) {
			index--;
		}
	}
	
	// Deletes the back element in this List. Pre: length()>0
	void deleteBack(){  
		if (length()<=0 || getIndex()<0) {
			throw new RuntimeException("List Error: deleteBack() called on empty List or cursor points to null");
		}
		Node temp = null;
		temp = back.prev;
		back = temp;
		back.next = null;
		temp = null;
		length--;
	}
	
	//Deletes cursor element in this List. Cursor is undefined. Pre: length()>0, getIndex()>=0
	void delete() {
		Node be4;
		Node l8r;
		if (length()<=0 || getIndex()<0) {
			throw new RuntimeException("List Error: delete() called on empty List or cursor points to null");
		}
		if(getIndex() == 0){
			deleteFront();
			length++;
		} else if(getIndex() == length()-1){
			deleteBack();
			length++;
		} else {
			be4 = cursor.prev;
			l8r = cursor.next;
			be4.next = l8r;
			l8r.prev = be4;
		}
		cursor = null;
		length--;
	}
	
	// Overides Object's toString method. Creates a string consisting of a space separated sequence of integers with front on the left and back on the right. The cursor is ignored.
	public String toString(){ 
	     String s = "";
	     for(Node N=front; N!=null; N=N.next){
	        //s += N.MatrixEntry + "\n";
	        s += N.MatrixEntry + " ";
	     }
	     return s;
	  }
}
	// Returns a new list representing the same intefer sequence as this list. The cursor in the new list is undefined, regardless of the state of the cursor in this List. This List is unchanged.
	/*List copy() {
		List sb = new List();
		moveTo(0);
		while(getIndex() < length()-1){
			sb.append(getElement());
			moveNext();
		}
		sb.append(getElement());
		
		cursor = null;
		sb.cursor = null;
		return sb;
	} */




