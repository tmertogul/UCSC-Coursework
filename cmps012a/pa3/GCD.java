/* GCD.java
 * Tim Mertogul
 * pa3
 * This program finds the greatest common devisor of two integers
 * */

import java.util.*;

class GCD{

   public static void main( String[] args ){
     int i, temp, dividend, divisor;
     Scanner sc = new Scanner(System.in);

     System.out.print("Enter a positive integer: ");
     while(true){
        while( !sc.hasNextInt() ){
        sc.next();
        System.out.print("Please enter a positive integer: ");
        }
     dividend = sc.nextInt();
        if(dividend>0){
        break;
        }
        System.out.print("Please enter a positive integer: ");
        }

     System.out.print("Enter another positive integer: ");
     while(true){
        while( !sc.hasNextInt() ){ 
        sc.next();
        System.out.print("Please enter a positive integer: ");
        }
        divisor = sc.nextInt();
        if(divisor>0){
        break;
        }
        System.out.print("Please enter a positive integer: ");
        }

   if(divisor>dividend){
      temp = divisor;
      divisor = dividend;
      dividend = temp;
   }
   int m = dividend, n = divisor, remainder = 2;
   while(remainder!=0) {
      if(remainder==0) {
      break;
      }
      else
      remainder = m%n;
      m = n;
      n = remainder;
   }  
   
   System.out.println("The GCD of "+dividend+" and "+divisor+" is "+m+"");
   }
}  

