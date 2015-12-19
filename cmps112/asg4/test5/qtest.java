// $Id: qtest.java,v 1.1 2015-12-08 21:35:10-08 - - $

import static java.lang.System.*;

class qtest {

   public static void main (String[] args) {
      queue<String> queue = new queue<String> ();
      for (String arg : args) queue.insert (arg);
      while (! queue.empty ()) out.println (queue.remove ());
   };

};

