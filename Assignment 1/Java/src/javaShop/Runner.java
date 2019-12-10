package javaShop;

import java.util.*;

public class Runner {

	public static int menuOptions(){
		
		// ask the user how they want to proceed
		System.out.println("\nPlease Choose and Option:");
		System.out.println("\nProcess an Order (Enter 1)");
		System.out.println("Purchase a Single Item (Enter 2)");
		System.out.println("Exit (Enter 0)\n");

		// create the scanner to take in user input
		Scanner scan = new Scanner(System.in);

		int c = scan.nextInt();
		scan.close();

		return c;
	}

	public static void main(String[] args) {
		Shop shop = new Shop("javaShop/stock.csv");
		
		int choice = menuOptions();
		System.out.println(choice);
		
		switch(choice){
			case 0:
				System.out.println("Thank you. Goodbye.");
				break;
			case 1: 
				System.out.println("You Selected 1");
				Customer custAcc = new Customer("javaShop/customer.csv");
				System.out.println(custAcc);
				System.out.println();
		
				//process order
				System.out.println("Thank you.\nYour order has not been processed today.\nPlease come back again soon.");
				
				break;
			case 2: 
				System.out.println("You Selected 2");
				break;
			default:
				System.out.println("\nYou have entered an invalid menu option. Please try again.\n");
		}

			
//		System.out.println(james);
//		shop.processOrder(james);
	}
}
