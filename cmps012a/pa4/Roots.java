/*
 * Roots.java
 * pa4
 * Program determines the real roots of a polynomial within a specified range.
 */

import java.util.*;
import java.util.Scanner;

public class Roots{

   public static void main( String[] args ) {
      Scanner sc = new Scanner(System.in);
      int degree;
      double leftendpoint, rightendpoint, tolerance, threshold, resolution;
      tolerance = Math.pow(10,-7);
      threshold = Math.pow(10,-3);
      resolution = Math.pow(10,-2);

      System.out.print("Enter the degree: ");
      degree = sc.nextInt();
      
      double[] polynomial = new double[degree+1];
      
      System.out.print("Enter the "+(degree+1)+" coefficients: ");
      for(int i=0; i<(degree+1); i++) {
          polynomial[i] = sc.nextDouble();
      }

      System.out.print("Enter the left and right endpoints: ");
         leftendpoint = sc.nextDouble();
         rightendpoint = sc.nextDouble();

      System.out.println(" ");

      double[] polynomialnew;
      diff(polynomial);
      polynomialnew = diff(polynomial);

      partition(polynomial, leftendpoint, rightendpoint, resolution, tolerance);

   }

   static double poly(double[] C, double x) {
      double sum;
      sum = 0;

      for(int i=0; i<C.length; i++) {
         sum += C[i]*Math.pow(x,i);
      } return sum;
   }

   static double[] diff(double[] C) {
      double[] pnew = new double[C.length-1];

      for(int i=0; i<(pnew.length); i++) {
         pnew[i] = C[i+1]*(i+1);
      }
      return pnew;
   }

   public static boolean oddRoot(double[] C, double a, double b) {
      if(poly(C,a)>0 && poly(C,b)<0) {
         return true;
      }
      if(poly(C,a)<0 && poly(C,b)>0) {
         return true;
      }
      if(Math.abs(poly(C,a)) == 0) {
         return true;
      }
      else {
         return false;
      }
   }

   static double findRoot(double[] C, double a, double b, double tolerance) {
      double m = (a + b)/2.0;
      double threshold = .001;

      if(Math.abs(poly(C,a)) < threshold) {
         return a;
      }
      if(Math.abs(poly(C,a)) < threshold) {
         return b;
      }
      while( b - a > tolerance) {
         m = (a + b) / 2.0;

         if(oddRoot(C, a, m)) {
            b = m;
         }
         if(oddRoot(C, m, b)) {
            a = m;
         }
      } 
      return m;
   }

   public static void partition(double[] C, double a, double b, double resolution, double tolerance) {
      double leftendpoint = a;
      double rightendpoint = a + resolution;
      boolean anyRoots = false;
      double threshold=0.001;
      double x;

      double[] plnew;
      diff(C);
      plnew = diff(C);

      while(rightendpoint < b) {
         if(oddRoot(C, leftendpoint, rightendpoint)) {
                System.out.print("Root found at ");
                System.out.printf("%.5f%n", findRoot(C, leftendpoint, rightendpoint, tolerance));
                anyRoots = true;
                leftendpoint += resolution;
                rightendpoint += resolution;
         }
         else if (oddRoot(plnew, leftendpoint, rightendpoint)) {
              x = findRoot(plnew, leftendpoint, rightendpoint, tolerance);        
              if(Math.abs(poly(C, x)) < threshold) {
                   System.out.print("Root found at ");
                   System.out.printf("%.5f%n", x);
                   anyRoots = true;
                   leftendpoint += resolution;
                   rightendpoint += resolution;
                   continue;
              }
            leftendpoint += resolution;
            rightendpoint += resolution;
            continue; 
         }
      leftendpoint += resolution;
      rightendpoint += resolution;     
      }
      if(oddRoot(C, leftendpoint, b)) {
           System.out.print("Root found at ");
           System.out.printf("%.5%n", findRoot(C, leftendpoint, b, tolerance));
           anyRoots = true;
      }
      else if(oddRoot(plnew, leftendpoint, b)) {
           if (Math.abs(poly(C, findRoot(plnew, leftendpoint, rightendpoint, tolerance))) < threshold ) {
               System.out.print("Root found at ");
               System.out.printf("%.5f%n", findRoot(plnew, leftendpoint, rightendpoint, tolerance));
               anyRoots = true;
           }
      }
      if (Math.abs(poly(C,b)) ==0) {
          System.out.print("Root found at ");
          System.out.printf("%.5f%n", b);
          anyRoots = true;
      }
      if(!anyRoots) {
           System.out.println("No roots were found in the specified range. ");
      }
  }
}   



