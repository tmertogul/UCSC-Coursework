CREATE VIEW customer_city(first_name, last_name, email, city_id) AS 
   SELECT dv_customer.first_name, dv_customer.last_name, dv_customer.email, dv_address.city_id 
   FROM dv_customer, cb_customers, dv_address  
   WHERE (dv_customer.last_name = cb_customers.last_name)
   AND (dv_customer.first_name = cb_customers.first_name)
   AND (dv_customer.address_id = dv_address.address_id);


CREATE VIEW district_stats(district, COUNT) AS
   SELECT dv_address.district, COUNT(*)
   FROM dv_address
   GROUP BY district
   ORDER BY COUNT(*) ASC;

SELECT * FROM district_stats
   ORDER BY COUNT DESC
   LIMIT 1;
SELECT COUNT(*) FROM district_stats
   WHERE COUNT = 1
   ORDER BY COUNT(*) ASC;
ALTER VIEW customer_city RENAME TO new_customer_city_view;
