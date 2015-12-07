/* Guess.java
 * Tim Mertogul
 * 1331402
 * pa2
 * Program that plays an interactice guessing game with the user
 */

import java.util.*;
import java.util.Scanner;

class Guess{

   public static void main( String[] args ){
      int guess, random;
      Scanner sc = new Scanner(System.in);
      random = (int)(10 * Math.random() + 1);

      System.out.println("");
      System.out.print("I'm thinkin of an integer in the range");
      System.out.println(" 1 to 10. You have three guesses.");
      System.out.println("");

      System.out.print("Enter your first guess: ");
      guess = sc.nextInt();

   if (guess == random) {
      System.out.println("You win!");
   }  else if (guess > random) {
      System.out.println("Your guess is too high.");
   }  else if (guess < random) {
      System.out.println("Your guess is too low.");
   }

   if (guess != random) {
      System.out.println("");
      System.out.print("Enter your second guess: ");
      guess = sc.nextInt(); 

   if (guess == random) {
      System.out.println("You win!");
   }  else if (guess > random) {
      System.out.println("Your guess is too high.");
   }  else if (guess < random) {
      System.out.println("Your guess is too low." );
   }

   if (guess == random) {
   }  else if (guess != random) {
      System.out.println("");
      System.out.print("Enter your third guess: ");
      guess = sc.nextInt();

   if (guess == random) {
      System.out.println("You win!");
   }  else if (guess > random) {
      System.out.println("Your guess is too high.");
   }  else if (guess < random) {
      System.out.println("Your guess is too low. ");
   }
   if (guess != random) {
      System.out.println("");
      System.out.println("You lose. The number was "+random+".");
   }
      else { }
   }
   }
      System.out.println("");
   }
}

