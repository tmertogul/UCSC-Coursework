import java.sql.*;
import java.util.*;

/**
 * The class implements methods of the video and bookstore database
 * interface.
 *
 * All methods of the class receive a Connection object through which all
 * communication to the database should be performed. Note: the
 * Connection object should not be closed by any method.
 *
 * Also, no method should throw any exceptions. In particular, in case
 * that an error occurs in the database, then the method should print an
 * error message and call System.exit(-1);
 */
public class StoreApplication {

	/**
	 * Return a list of phone numbers of customers, given a first name and
	 * last name.
	 */
	public List<String> getCustomerPhoneFromFirstLastName(Connection connection,
			String firstName, String lastName) {
		List<String> result = new ArrayList<String>();

		try(Statement stmt = connection.createStatement()){
			String query = "SELECT dv_address.phone FROM mg_customers, dv_address WHERE mg_customers.first_name = '"
							+firstName+"' AND mg_customers.last_name = '"
							+lastName+"' AND dv_address.address_id = mg_customers.address_id";
			try (ResultSet res = stmt.executeQuery( query )) 
			{
				if (res != null) 
				{
					// Retrieving results from ResultSet 
					while (res.next()) 
					{
						// retrieve tuple by tuple
						//String phoneNum = res.getString(1);   // Get first attribute 
						result.add(res.getString(1));
						//String address = res.getString(2); // Get second attribute
					}
				}
			} 
			catch (SQLException e) 
			{
				System.err.println("Error while executing query: " + e);
				e.printStackTrace();
			}
		}
		catch (SQLException e) {
			System.err.println("Error while creating connection: " + e);
			e.printStackTrace();
		}

		return result;
	}

	/**
	 * Return list of film titles whose length is is equal to or greater
	 * than the minimum length, and less than or equal to the maximum
	 * length.
	 */
	public List<String> getFilmTitlesBasedOnLengthRange(Connection connection,
			int minLength, int maxLength) {
		List<String> result = new LinkedList<String>();

		try(Statement stmt = connection.createStatement()){
			String query = "SELECT dv_film.title FROM dv_film WHERE dv_film.length >= "
							+minLength+" AND dv_film.length <= "+maxLength+" ORDER BY dv_film.title ASC";
			try (ResultSet res = stmt.executeQuery( query )) 
			{
				if (res != null) 
				{
					// Retrieving results from ResultSet 
					while (res.next()) 
					{
						// retrieve tuple by tuple
						//String phoneNum = res.getString(1);   // Get first attribute 
						result.add(res.getString(1));
						//String address = res.getString(2); // Get second attribute
					}
				}
			} 
			catch (SQLException e) 
			{
				System.err.println("Error while executing query: " + e);
				e.printStackTrace();
			}
		}
		catch (SQLException e) {
			System.err.println("Error while creating connection: " + e);
			e.printStackTrace();
		}

		return result;
	}

	/**
	 * Return the number of customers that live in a given district and
	 * have the given active status.
	 */
	public final int countCustomersInDistrict(Connection connection,
			String districtName, boolean active) {
		int result = -1;

		try(Statement stmt = connection.createStatement()){
			String query = "SELECT COUNT(*) FROM mg_customers, dv_address WHERE dv_address.address_id = "
                            +"mg_customers.address_id AND dv_address.district = '"+districtName 
                            +"' AND mg_customers.active = "+active;
			try (ResultSet res = stmt.executeQuery( query )) 
			{
				if (res != null) 
				{
					res.next();
					result = res.getInt(1);
				}
			} 
			catch (SQLException e) 
			{
				System.err.println("Error while executing query: " + e);
				e.printStackTrace();
			}
		}
		catch (SQLException e) {
			System.err.println("Error while creating connection: " + e);
			e.printStackTrace();
		}

		return result;
	}

	/**
	 * Add a film to the inventory, given its title, description,
	 * length, and rating.
	 *
	 * Your query will need to cast the rating parameter to the
	 * enumerated type mpaa_rating. Whereas an uncast parameter is
	 * simply a question mark, casting would look like ?::mpaa_rating 
	 */
	public void insertFilmIntoInventory(Connection connection, String
			title, String description, int length, String rating)
	{
		try(PreparedStatement stmt = connection.prepareStatement("INSERT INTO dv_film (title, description, length, rating)"
			                  +" VALUES (?, ?, ?, ?::mpaa_rating)")){
			stmt.setString(1, title);
			stmt.setString(2, description);
			stmt.setInt(3, length);
			stmt.setString(4, rating);
			stmt.executeUpdate();
		}
		catch (SQLException e) {
			System.err.println("Error while creating connection: " + e);
			e.printStackTrace();
		}
	}

	/**
	 * Constructor
	 */
	public StoreApplication()
	{}

};
