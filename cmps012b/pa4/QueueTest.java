
public class QueueTest {

   public static void main(String[] args){


      //string v;
      Queue A = new Queue();

      //A.dequeue();
      A.enqueue("1");
      //System.out.println(A + " = 1");

      A.enqueue("2");
      A.enqueue("3");
      A.enqueue("6");
      A.enqueue("4");

      System.out.println(A);

      System.out.println(A.peek());

      A.dequeue();
      A.dequeue();
      A.dequeue();

      System.out.println(A + " = 2");


      A.isEmpty();

      A.dequeueAll();
      System.out.println(A + "lineA");

   }



}
