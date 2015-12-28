/* Tim Mertogul
 * 1331402
 * CMPS12B
 * 07/09/13
 * FileReverse Program that reverses the contents of an input file to an output file
 * FileReverse.java 
 */

import java.io.*;
import java.util.Scanner;

class FileReverse{

   public static void main(String[] args) throws IOException{
      Scanner in = null;
      PrintWriter out = null;
      String line = null;
      String[] token = null;
      String str = null;
      int n, i, lineNumber = 0;
      if(args.length < 2){
         System.out.println("Usage: FileCopy infile outfile"); 
         System.exit(1);
      }
      in = new Scanner(new File(args[0]));
      out = new PrintWriter(new FileWriter(args[1]));
      in.useDelimiter("\n");
      
      while( in.hasNext() ){
         lineNumber++;
         line = in.next() + " "; // add space so split works on blank lines 
         token = line.split("\\s+"); // split line around white space
         n = token.length;
         for(i=0; i<n; i++){
            str = token[i];
            
            out.println(stringReverse(str, str.length()));
         }
      }
      in.close();
      out.close();
   }

   public static String stringReverse(String s, int n){
      if (n > 0) { return s.substring(n-1, n) + stringReverse(s, n-1); }
      else { return ""; }
   }
}
