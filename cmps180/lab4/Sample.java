import java.sql.*;

/**
 * A sample class that connects to PostgreSQL and runs a simple query. For
 * queries which are more complicated, you may need to use a PreparedStatement.
 * See http://jdbc.postgresql.org/documentation/head/query.html for more
 * details. The jdbc documentation for PostgreSQL can be found here:
 * https://jdbc.postgresql.org/documentation/head/index.html
 * 
 * @author sanjana
 *
 **/
public class Sample
{
    public static void main(String args[]) throws SQLException
    {
    	//Load the driver
		try 
		{
			Class.forName("org.postgresql.Driver");
		} 
		catch (ClassNotFoundException e1) 
		{
			System.out.println("Class not found, exiting");
			e1.printStackTrace();
			return;
		}

		// Make the Connection
		try (Connection conn = DriverManager.getConnection(
				"jdbc:postgresql://localhost:5432/tim",
				"tim", "");
				Statement stmt = conn.createStatement()) 
				{
			
			/*****************************************************************
			 * Your database name is your login name , so for login smaiya the
			 * string would look like "jdbc:postgresql://db.ic.ucsc.edu/smaiya",
			 * "smaiya" , "password"
			 *****************************************************************/
			
			/*******************************************************************
			 * See http://www.oracle.com/technetwork/articles/java/trywithresources-401775.html
			 * for more information about try-with-resources. Make sure that your 
			 * code does not leak connections!
			 *******************************************************************/
			// Query to be executed, results are returned to ResultSet
			try (ResultSet res = stmt.executeQuery(" Select * from dv_address")) 
			{
				if (res != null) 
				{
					// Retrieving results from ResultSet 
					while (res.next()) 
					{
						// retrieve tuple by tuple
						String addressId = res.getString(1);   // Get first attribute 
						System.out.print(addressId);
						String address = res.getString(2); // Get second attribute
						System.out.println("  " + address);
					}
					//System.out.println("sdone with results");
				}
			} 
			catch (SQLException e) 
			{
				System.err.println("Error while executing query: " + e);
				e.printStackTrace();
			} 
		}
		catch (SQLException e) 
		{
			System.err.println("Error while creating connection: " + e);
			e.printStackTrace();
		}
    }
}


