/*Tim Mertogul
* 1331402
* CMPS101 Summer14
* 07/02/14
* ADD DESCRIPTION
* List.java
*/

public class List {
	
	private class Node {
		//String element;  //word in list
		int data;        
		int index; 
		Node prev;
		Node next;
		Node cursor;  //current value
		
		Node(int data){  //constructor
			this.data = data;
			this.next = next;
			this.prev = prev;
			this.index = index;
		}
		// toString:  Overides Object's toString method.
	//public String toString() { return String.valueOf(element); }
		
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

	int length() {
		return length;
	}
	
	int getIndex(){
		if (cursor == null) {
			return -1;
		}
		else {
			return index;
		}
	}	
	
	int front(){ 
		if(length() > 0){
			return front.data; 
		} else {
			throw new RuntimeException("List Error: front() called on empty List");
		}
	}
	
	int back(){ 
		if(length() > 0){
			return back.data; 
		} else {
			throw new RuntimeException("List Error: back() called on empty List");
		}
	}
	
	int getElement(){
		if(length() > 0 && getIndex() >=0 ){
			return cursor.data; 
		} else {
			throw new RuntimeException("List Error: getElement() called on empty List or cursor points to null");
		}
	}
	
	boolean equals(List L){
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
		}
		return true;
	}
	
	void clear(){ 
		front = back = cursor = null;
		index = -1;
		length = 0;
	}
	
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
	
	void movePrev(){
		if(getIndex() > length()-1){
			cursor = null;
		} else if (getIndex() == -1 || getIndex() == 0){
			cursor = null;
		} else { 
			cursor = cursor.prev;
			index--;
		}
	}		
	
	void moveNext() {
		if(getIndex() == length()-1){
			cursor = null;
		} else if (getIndex() == -1){
			cursor = null;
		} else {
			cursor = cursor.next;
			index++;
		}
	}
	
	void insertBefore(int data){
		if(getIndex() == 0){
			prepend(data);
		}else if(getIndex() >= 0 && length() > 0 ){
			Node newBC = new Node(data);
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
		else{
			
		}	
	}
	
	void insertAfter(int data){
		if(getIndex() == length()-1 ){
			append(data);
		}
		else{
			Node newAC = new Node(data);
			Node temp = null;
			temp = cursor.next;
			newAC.next = temp;
			temp.prev = newAC;
			newAC.prev = cursor;
			cursor.next = newAC;
			length++;	
		}
	}
	
	void deleteFront(){
		Node temp;
		temp = front;
		front = front.next;
		temp = null;
		length--;
		if (getIndex() != -1) {
			index--;
		}
	}
	
	void deleteBack(){  
		Node temp = null;
		temp = back.prev;
		//temp.prev = back.prev;
		back = temp;
		back.next = null;
		temp = null;
		length--;
	}
	
	void delete() {
		Node be4;
		Node l8r;
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
	
	public String toString(){ 
	     String s = "";
	     for(Node N=front; N!=null; N=N.next){
	        s += N.data + " ";
	     }
	     return s;
	  }
	
	List copy() {
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
	} 

	void prepend(int data) {
		Node newF = new Node(data);
		Node temp = null;
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
	
	void append(int data) { 
		Node newB = new Node(data);
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
}



