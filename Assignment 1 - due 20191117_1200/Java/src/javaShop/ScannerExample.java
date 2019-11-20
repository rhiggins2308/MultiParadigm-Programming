package javaShop;

import java.util.*;

public class ScannerExample {

	public static void main(String args[]) {
		// create the scanner to take in user input
		Scanner scan = new Scanner(System.in);

		// ask the user for what they want to buy and save as string
		System.out.println("What product do you want to buy?");
		String productName = scan.nextLine();

		// Ask how many they want and save as a integer
		System.out.println("How many " + productName + " do you want?");
		int amount = scan.nextInt();

		// find out how much money they have to pay you with
		System.out.println("How much money do you have?");
		double cash = scan.nextDouble();

		// Print the information
		System.out.println("You want to buy " + amount + " " + productName + " and you have " + cash + ".");
		scan.close();

	}

}
