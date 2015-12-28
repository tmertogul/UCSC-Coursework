public class DictionaryTest{

   public static void main(String[] args){
      String v;
      Dictionary A = new Dictionary();

     A.insert("3","j");
      A.insert("4","B");
      A.insert("5","C");
      A.insert("6","BC");
      A.insert("7","CD");

      System.out.println(A.isEmpty());
      //A.insert("5","exception"); 
      
      System.out.println(A);


      A.delete("7");
      System.out.println(A);
       A.delete("6");
       System.out.println(A);
       A.delete("5");
       System.out.println(A);
       A.delete("4");
       System.out.println(A);
       A.delete("3");
       System.out.println(A);
        A.insert("6","BC");
         A.insert("5","C");
       System.out.println(A);
       


        A.makeEmpty();
//      System.out.println(A);

       System.out.println(A.isEmpty());

/*       A.delete("3");
      System.out.println(A);
       //A.delete("2");
      System.out.println(A);
       A.delete("4");
      System.out.println(A);
       A.delete("5");
      System.out.println(A);
       A.delete("7");
      System.out.println(A);
       A.delete("6");
      System.out.println(A);


      System.out.println(A);

      System.out.println(A.isEmpty());

        A.makeEmpty();
      System.out.println(A);

        System.out.println(A.isEmpty());

      A.insert("3","j");
      System.out.println(A);


      System.out.println("T list is empty " + A.isEmpty());
      
      A.insert("3","j");
      A.insert("4","B");
      A.insert("5","C");
      A.insert("6","BC");
      A.insert("7","CD");

      System.out.println(A);

      System.out.println("B 4 should = " + A.lookup("4"));
      A.delete("4");
      System.out.println("4 size = " + A.size());
      System.out.println("F list is empty " + A.isEmpty());
      System.out.println("null 4 shouldnt = " + A.lookup("4"));

      A.insert("4","B");

      System.out.println(A);


        System.out.println(A.isEmpty());
      System.out.println(A.size());

        A.makeEmpty();
        System.out.println(A.isEmpty());
        System.out.println(A);

//      A.insert("4","d");

//      A.delete("8");



      //A.remove("6");

      //System.out.println(A);
      //System.out.println("DT - " + A.isEmpty());

      //System.out.println("5 = " + A.lookup("5")); 
      //System.out.println("9 = " + A.lookup("9"));

      //System.out.println("size = " + A.size());

      //A.insert("4","j");
      //A.insert("3","j");
      
      //A.delete("9");
      //A.delete("5");


      //System.out.println("D5 = " + A.lookup("5"));
      //System.out.println("Dsize = " + A.size());

      //v = A.lookup("3");
      //System.out.println("key=3 "+(v==null?"not found":("value="+v)));

      //A.makeEmpty();
      //System.out.println("DT - " + A.isEmpty());
*/
   }
}

