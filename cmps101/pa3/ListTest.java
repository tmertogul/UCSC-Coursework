/*Tim Mertogul
* 1331402
* CMPS101 Summer14
* 07/19/14
* Testfile for List ADT for PA3
* ListTest.java
*/


public class ListTest{
	public static void main(String[] args){
		System.out.println("ListTest Compiled and running");
		
		List A = new List();
		      List B = new List();
		      
		      for(int i=1; i<=20; i++){
		         A.append(i);
		         B.prepend(i);
		      }
		      System.out.println(A);
		      System.out.println(B);
		      
		      for(A.moveTo(0); A.getIndex()>=0; A.moveNext()){
		         System.out.print(A.getElement()+" ");
		      }
		      System.out.println();
		      for(B.moveTo(B.length()-1); B.getIndex()>=0; B.movePrev()){
		         System.out.print(B.getElement()+" ");
		      }
		      System.out.println();
		      
		      /*List C = A.copy();
		      System.out.println(A.equals(B));
		      System.out.println(B.equals(C));
		      System.out.println(C.equals(A));*/
		      
		      A.moveTo(5);
		      A.insertBefore(-1);
		      A.moveTo(15);
		      A.insertAfter(-2);
		      A.moveTo(10);
		      A.delete();
		      System.out.println(A);
		      A.clear();
		      System.out.println(A.length());
		
		/*
	List A = new List();
    List B = new List();
    List D = new List();

	System.out.println(A.equals(D));
	A.moveTo(5);
    System.out.println(D.equals(A));

	     
    for(int i=1; i<=20; i++){
         A.append(i);
         B.prepend(i);
         D.append(i);
      }

      System.out.println(A);
      System.out.println(B);

*/

	}
}

/*

          
      for(A.moveTo(0); A.getIndex()>=0; A.moveNext()){
         System.out.print(A.getElement()+" ");
      }
      System.out.println();
      for(B.moveTo(B.length()-1); B.getIndex()>=0; B.movePrev()){
         System.out.print(B.getElement()+" ");
      }
      System.out.println();
      
      List C = A.copy();

      System.out.println(" ");

	  System.out.println("C.front = 1 = "+C.front()+", C.back = 20 = "+C.back());
	  System.out.println("C.front = 1 = "+C.front()+", C.back = 20 = "+C.back());
	  System.out.println(A.length());
	  System.out.println(C.length());
	  System.out.println(C.getIndex());
	  System.out.println(A.getIndex());


      System.out.println(A.equals(B));
      System.out.println(B.equals(C));
      System.out.println(C.equals(A));
      System.out.println(A.equals(C));
      

      A.moveTo(5);
      A.insertBefore(-1);
      A.moveTo(15);
      A.insertAfter(-2);
      A.moveTo(10);
      A.delete();
      System.out.println(A);
      A.clear();
      System.out.println(A.length());

	*/

/*
	System.out.println(A);
	System.out.println("A.front = 1 = "+A.front()+", A.back = 20 = "+A.back());

	System.out.println("printing B:");
    System.out.println(B);
    System.out.println("B.front = 20 = "+B.front()+", B.back = 1 = "+B.back());
    System.out.println("B.front  = 20 = "+B.front());
	System.out.println("B.cursor is moving to index 0");
	B.moveTo(0);
	System.out.println("B.data = 20 = "+B.getElement());
	System.out.println("B.next x3 is moving to index 3, element 17");
	B.moveNext();
	B.moveNext();
	B.moveNext();
	System.out.println("B.data = 17 = "+B.getElement());
    System.out.println("B.index = 3 = "+B.getIndex());

	System.out.println("B.prev x2 is moving to index 1, element 19");
	B.movePrev();
	B.movePrev();
	System.out.println("B.data = 19 = "+B.getElement());
    System.out.println("B.index = 1 = "+B.getIndex());




    System.out.println("B.length-1  = 19 ="+(B.length()-1));
	System.out.println("B.cursor is moving to index 19");
	B.moveTo(B.length()-1);
	System.out.println("getIndex of B.length-1 = 19 = "+B.getIndex());
    System.out.println("getElement of B.length-1 = 20 = "+B.getElement());


	System.out.println("printing A element:");  
    for(A.moveTo(0); A.getIndex()>=0; A.moveNext()){
		System.out.print(A.getElement()+" ");
	}
	System.out.println();
	
	System.out.println("printing B element backwards:");      
	for(B.moveTo(B.length()-1); B.getIndex()>=0; B.movePrev()){
		System.out.print(B.getElement()+" ");
	}
	System.out.println();
	     
	List C = A.copy();
	System.out.println(A.equals(B));
	System.out.println(B.equals(C));
	System.out.println(C.equals(A));
	   
	System.out.println("Cursor moving to index 5");
	A.moveTo(5);
	//System.out.println("getIndex = 5 = "+A.getIndex());

	A.insertBefore(-1);
	System.out.println("Cursor moving to index 15");
	
	A.moveTo(15);
	A.insertAfter(-2);
	
	System.out.println("Cursor moving to index 10");
	A.moveTo(10);
	A.delete();
	System.out.println("printing A:");
	System.out.println(A);
	System.out.println("Clearing A, printing A.length:");
	A.clear();
	System.out.println(A.length());*/

 //     List A = new List();
//      List B = new List();
      
/*      for(int i=1; i<=20; i++){
         A.append(i);
         B.prepend(i);
      }
      System.out.println(A);
      System.out.println(B);
      
      for(A.moveTo(0); A.getIndex()>=0; A.moveNext()){
         System.out.print(A.getElement()+" ");
      }
      System.out.println();
      for(B.moveTo(B.length()-1); B.getIndex()>=0; B.movePrev()){
         System.out.print(B.getElement()+" ");
      }
      System.out.println();
      
      List C = A.copy();
      System.out.println(A.equals(B));
      System.out.println(B.equals(C));
      System.out.println(C.equals(A));
      
      A.moveTo(5);
      A.insertBefore(-1);
      A.moveTo(15);
      A.insertAfter(-2);
      A.moveTo(10);
      A.delete();
      System.out.println(A);
      A.clear();*/
      /*System.out.println("length = 0 = "+A.length());
      System.out.println("getIndex = -1 = "+A.getIndex());
      A.moveNext();
      System.out.println("getIndex = -1 = "+A.getIndex());

	  	  
	  A.prepend(5);
	  System.out.println("length = 1 = "+A.length());
	  System.out.println("getIndex = 5 = "+A.getIndex());
	  A.moveNext();
	  System.out.println("getIndex = -1 = "+A.getIndex());

	  A.clear();
	  System.out.println("length = 0 = "+A.length());*/
	/*
	  A.append(2);
	  A.prepend(10);
	  A.append(3);
   	  A.prepend(4);
      A.append(11);
	  A.prepend(9);
	  A.prepend(6);
  	  System.out.println("A.length = 7 = "+A.length());
	  System.out.println("A:");
	  System.out.println(A);
	  System.out.println("A.front = 6 = "+A.front());
	  System.out.println("A.back = 11 = "+A.back());
	  /*
	  A.deleteFront();
	  System.out.println("A.length = 6 = "+A.length());
	  System.out.println("A:");
	  System.out.println(A);
	  System.out.println("A.front = 9 = "+A.front());
	
	  A.deleteBack();
	  System.out.println("A.length = 5 = "+A.length());
	  System.out.println("A:");
	  System.out.println(A);
	  System.out.println("A.back = 3 = "+A.back());
	  /*
	  //System.out.println("getElement = null = "+A.getElement());
	  A.moveTo(4);
	  //System.out.println("getElement = 4 = "+A.getElement());
	  A.moveTo(3);
	  //System.out.println("getElement = 3 = "+A.getElement());
	  A.moveNext();
	  //System.out.println("getElement = 11 = "+A.getElement());
	  A.movePrev();
	  System.out.println("getElement = 3 = "+A.getElement());
      A.movePrev();
      A.movePrev();
      A.movePrev();
 	  System.out.println("getElement = 4 = "+A.getElement());
      A.insertBefore(7);
	  System.out.println("A:");
	  System.out.println(A);
*/
