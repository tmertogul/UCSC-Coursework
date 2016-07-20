SELECT dv_customer.first_name, dv_customer.last_name, dv_address.phone FROM dv_customer, cb_customers, dv_address
   WHERE (dv_customer.last_name = cb_customers.last_name)
   AND (dv_customer.first_name = cb_customers.first_name)
   AND (dv_customer.address_id = dv_address.address_id)
   ORDER BY dv_customer.last_name;

SELECT DISTINCT cb_books.publisher, COUNT(*) FROM cb_books 
   WHERE(cb_books.edition = 1)
   GROUP BY cb_books.publisher
   ORDER BY COUNT(*) DESC;

SELECT mg_customers.first_name, mg_customers.last_name FROM mg_customers 
   WHERE mg_customers.address_id IN (SELECT dv_address.address_id FROM dv_address
      WHERE dv_address.district IN (SELECT dv_address.district FROM dv_address
         GROUP BY dv_address.district
         ORDER BY COUNT(*) DESC
         LIMIT 1));

SELECT dv_film.rating, COUNT(*) FROM dv_film 
   GROUP BY dv_film.rating
   ORDER BY COUNT(*) DESC
   LIMIT 1;

SELECT cb_authors.first_name, cb_authors.last_name, COUNT(cb_books.author_id) FROM cb_authors, cb_books
    WHERE cb_books.author_id = cb_authors.author_id
    GROUP BY cb_authors.first_name, cb_authors.last_name
    ORDER BY COUNT(cb_books.author_id) DESC
    LIMIT 10;
