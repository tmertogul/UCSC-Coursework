
import java.io.*;
import java.util.Scanner;

public class Simulation{
/*
// The following function may be of use in assembling the initial backup and/or
// storage queues.  You may use it as is, alter it as you see fit, or delete it
// altogether.
*/
   public static Job getJob(Scanner in) {
      String[] s = in.nextLine().split(" ");
      int a = Integer.parseInt(s[0]);
      int d = Integer.parseInt(s[1]);
      return new Job(a, d);

      /*int i=0;
      Job[] jobIn = null;
      while(i<3){
         String[] s = in.nextLine().split(" ");
         int a = Integer.parseInt(s[0]);
         int d = Integer.parseInt(s[1]);
         Job temp = new Job(a, d);
         jobIn[i] = temp;
         i++;
      }
      return jobIn;*/
   }

/*
// The following stub for function main contains a possible algorithm for this
// project.  Follow it if you like.  Note that there are no instructions below
// which mention writing to either of the output files.  You must intersperse
// those commands as necessary.
*/
   public static void main(String[] args) throws IOException{
      Scanner in = null;
      PrintWriter rpt = null;
      PrintWriter trc = null;


   //    1.  check command line arguments
      if(args.length < 1){
         System.out.println("Usage: Simulation input_file");
         System.exit(1);
      }

   //    2.  open files for reading and writing
      in = new Scanner(new File(args[0]));
      rpt = new PrintWriter(new FileWriter(args[0] + ".rpt"));
      trc = new PrintWriter(new FileWriter(args[0] + ".trc"));

   //    3.  read in m jobs from input file
      in.useDelimiter("\n");
      int m;
      int lineNumber = 0;
      String[] line1 = in.nextLine().split(" ");
      m = Integer.parseInt(line1[0]);
      //m = line.split("//s+");
      //trc.println(m);
      lineNumber++;

      rpt.println("Report file: " + args[0] + ".rpt");
      trc.println("Trace file: " + args[0] + ".trc");
      rpt.println(m + " Jobs:");
      trc.println(m + " Jobs:");

      Job toDo = null;
      Queue storage = new Queue();
      while( in.hasNextLine() ){
         storage.enqueue(getJob(in));
      }
      rpt.println(storage);
      trc.println(storage);
      rpt.println();
      trc.println();
      rpt.println("***********************************************************");
      //Job front = (Job) (storage.peek());
      //trc.println(front);
      //trc.println(myQueue);

   //    4.  run simulation with n processors for n=1 to n=m-1  {
	  boolean notDone = true;
	  int[] pNum = new int[m];
	  int p = 0;
	  for(int i=0; i<m; i++){
	     pNum[i] = p;
	     p++;
	  }
	  int timeNow = 0;
	  //while(n<m){
      for(int n=1; n<m-1; n++){
      //int n=3;
      //    5.   declare and initialize an array of n processor Queues and any 
      //         necessary storage Queues
         trc.println("*****************************");
	     trc.println(pNum[n] + "processor:");
	     trc.println("*****************************");
         //Queue[] processor = new Queue[n];
         //Queue processor = new Queue();
         //Queue complete = new Queue();
         Queue processor[] = new Queue[n];
         Queue complete = new Queue();
         //processor[0] = storage;

         //Job Front = (Job) (storage.peek());
         //Job Front = new Job();
//6. - while loop
         int t=0;
         while( notDone == true ){   //step #6
	        //Job front = new Job();
            Job front = (Job) (storage.peek());
            int arrival = front.getArrival();
            //trc.println("time=" + timeNow);
            
            if(timeNow == 0){
	           //front = (Job) (storage.peek());
	           //int arrival = front.getArrival();
	           trc.println("time=" + timeNow);
	           trc.println(pNum[0] + ": " + storage);
	           trc.println(pNum[1] + ": " + complete);
	           trc.println();
	           //timeNow = arrival;
	        }   
	        //timeNow = t;
	        if(timeNow == arrival){
		       //int startTime = timeNow + arrival;
		       complete.enqueue(front);
		       front.computeFinishTime(timeNow);
			   timeNow++;
			   //if(){
			      storage.dequeue();
		       //};
			
               trc.println("time=" + timeNow);
			   trc.println(pNum[0] + ": " + storage);

			   trc.println(pNum[1] + ": "+ complete);
			   trc.println();
			
		       
			   int finishT = front.getFinish();
		       //trc.println("finishT = " + finishT);
		       
		       //front = (Job) (storage.peek());
			   //arrival = front.getArrival();
			   
			   //timeNow++;
        	}
            else if (timeNow != arrival) {
	           timeNow++;
            }
            //t++; 
 	        /*
            if ( timeNow == arrival ) {
	           complete.enqueue(front);
	           //front.computeFinishTime(timeNow);
		       trc.println("time=" + timeNow);
		       storage.dequeue();
		       //toEmpty.dequeue();
			   trc.println(pNum[0] + ": " + storage);
			   trc.println(pNum[1] + ": "+ complete);
			   trc.println(); 
            }
            int finishT = front.getFinish();
            if (timeNow == finishT) {
	           //Job addBack = (Job) (complete.peek());
	           storage.enqueue(front);
	           //complete.dequeue();
               trc.println("adding back" + storage);
            }
            //trc.println("Arrival = " + arrival);
            //trc.println(front);
            //storage.dequeue();
            int g = 1;
            while(g<m){
                rpt.println(g + " processor: totalWait= , maxWait= , averageWait=   ");
                g++;
             }*/
         
            Job resetP = (Job) (storage.peek());
            if( resetP.getFinish() != -1 ){
	           notDone = false;
            }
            if(timeNow == 5){
               notDone = false;
            }
         }
   }
         //trc.println(processor[i]);
         //trc.println(storage);

   //    6.      while unprocessed jobs remain  {
         //while(storage.isEmpty() != true){
            
            //Job inLine = (Job) (storage.peek());
            //trc.println("waiting = " + inLine);

         //}
   //    7.          determine the time of the next arrival or finish event and 
   //                update time



   //    8.          complete all processes finishing now



   //    9.    if there are any jobs arriving now, assign them to a processor
   //          Queue of minimum length and with lowest index in the queue array.



   //    10.     } end loop



   //    11.     compute the total wait, maximum wait, and average wait for 
   //            all Jobs, then reset finish times
             

   //    12. } end loop
   //pNum++;

   //    13. close input and output files
   in.close();
   rpt.close();
   trc.close();

   }
}
