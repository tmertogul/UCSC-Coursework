public class ListTest{
   public static void main(String[] args){
      List<String> A = new List<String>();
      List<Double> B = new List<Double>();
      String get;
 

      System.out.print("Size = ");
      System.out.println(A.size());
      System.out.print("isEmpty = ");
      System.out.println(A.isEmpty());

      A.add(1, "one");
      B.add(1, 1.07);
      A.add(2, "two");
      A.add(3, "three");
      A.add(4, "four");
      A.add(5, "five");


      System.out.println("Adding 1 2 3 4 5");
      System.out.println("A: "+A);
      System.out.print("Size = ");
      System.out.println(A.size());

      System.out.println("A.equals(B) is "+A.equals(B));
      System.out.println("B.equals(A) is "+B.equals(A));


      System.out.print("Get 3 = ");
      get = A.get(3);
      System.out.println(get);

      A.remove(2);
      System.out.println("Removing 2");

      System.out.println("A: "+A);
      System.out.print("Size = ");
      System.out.println(A.size());

      A.removeAll();
      System.out.println("A: "+A);
      System.out.print("Size = ");
      System.out.println(A.size());

     


//      A.setIndex("very");
//      B.setSecond(-3.4);
//      System.out.println(A);
//      System.out.println(B);

/*      List<String> A2 = new List<String>();
      List<List<String> > pA = new List<List<String> >();
      System.out.println(pA);
      
      List<String> A3 = new List<String>();
      System.out.println(A.equals(B));
      System.out.println(A.equals(A2));
      System.out.println(A.equals(A3));
      System.out.println(A.equals(pA));
*/
   }
}
