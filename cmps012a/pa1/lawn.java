/* lawn.java
 * Tim Mertogul
 * 1331402
 * pa1
 * This program makes simple calculations
 */

import java.util.*;

class lawn{

   public static void main( String[] args ){
      double lotheight, lotwidth, lotarea, househeight, housewidth, housearea, lawn, rate, time;
      int h, m, xs;
      String s;
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter the length and width of the lot, in feet: ");
      lotwidth = sc.nextDouble();
      lotheight = sc.nextDouble();
      lotarea = lotwidth*lotheight;
 
      System.out.print("Enter the length and width of the house, in feet: ");
      housewidth = sc.nextDouble();
      househeight = sc.nextDouble();
      housearea = housewidth*househeight;
      lawn = lotarea-housearea;
      System.out.print("The lawn area is: ");
      System.out.println(lawn+" square feet."); 

      System.out.print("Enter the mowing rate, in square feet per second: ");
      rate = sc.nextDouble();
      time = lawn/rate;

      xs = (int) Math.round(time);
      m = xs/60;
      xs = xs%60;
      h = m/60;
      m = m%60;

      s = ( xs==1 ? "singular" : "plural" );

      System.out.print("The mowing time is: ");
      System.out.println(h+" hour"+(h==1?"":"s")+" "+m+" minute"+(m==1?"":"s")+" and "+xs+" second" + (xs==1?"":"s")+".");

   }
}

