import java.sql.*;
import java.io.*;
import java.util.*;

/**
 * A sample class that connects to PostgreSQL and runs a simple query.
 *
 * Note: Your database name is your login name, so for login jsmith, you would
 * have : getConnection("jdbc:postgresql://cmps180-db.lt.ucsc.edu/jsmith",
 * "jsmith" , "password");
 */
public class Driver
{
    public static void main(String[] args) {
    	
    	Connection connection = null;
    	try {
    		//Register the driver
    		Class.forName("org.postgresql.Driver"); 
    		// Make the connection
    		connection = DriverManager.getConnection(
    				"jdbc:postgresql://localhost:5432/tim",
                    "tim", ""); 

    		StoreApplication app = new StoreApplication();
    		List<String> phoneNumbers = app.getCustomerPhoneFromFirstLastName(
    				connection, 
    				"Mary", 
    				"Smith");
            phoneNumbers.forEach(System.out::println);
            System.out.println("----------------\n");

    		/************ Print the phone numbers here: ****************/

    		List<String> filmTitles = app.getFilmTitlesBasedOnLengthRange(
    				connection, 
    				45, 
    				47);
            filmTitles.forEach(System.out::println);
            System.out.println("----------------\n");
    		
    		/************* Print the film titles here: *****************/

    		int count = app.countCustomersInDistrict(
    				connection, 
    				"Buenos Aires",
    				true);
            System.out.println(count);
            System.out.println("----------------\n");

    		/************ Print the customer count here: **************/
    		
    		// add a film to the database
    		app.insertFilmIntoInventory(
    				connection, 
    				"Sequel to the Prequel",
    				"Memorable", 
    				98, 
    				"PG-13");
    	}
    	catch (SQLException | ClassNotFoundException e) {
    		System.out.println("Error while connecting to database: " + e);
    		e.printStackTrace();
    	}
    	finally {
    		if (connection != null) {
    			// Closing Connection
    			try {
					connection.close();
				} catch (SQLException e) {
					System.out.println("Failed to close connection: " + e);
					e.printStackTrace();
				}
    		}
    	}
    }
}
