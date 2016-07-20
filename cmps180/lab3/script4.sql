DELETE FROM dv_address WHERE address_id = 1;
DELETE FROM cb_authors WHERE author_id = 1;

INSERT INTO cb_books(title, author_id, edition, publisher) 
   VALUES('Book Title', 88, 1, 'Tim Publishing');
INSERT INTO cb_books(title, author_id, edition, publisher) 
   VALUES('!Book Title', 88, '-1', '!Tim Publishing');

INSERT INTO mg_customers (first_name, last_name, email, address_id, active) 
   VALUES('Timur', 'Mertogul', 'slofire94@gmail.com', 8, 't');
INSERT INTO mg_customers (first_name, last_name, email, address_id, active) 
   VALUES('Timur', 'Mertogul', 'slofire94@gmail.com', NULL, 't');
INSERT INTO mg_customers (first_name, last_name, email, active) 
   VALUES('Timur', 'Mertogul', 'slofire94@gmail.com', 't');

INSERT INTO dv_address (address_id, address, district, city_id, postal_code, phone) 
   VALUES('1000', '1844 Corralitos Ave', 'California', '69', '93401', '8053059134');
INSERT INTO dv_address (address_id, address, district, city_id, postal_code, phone) 
   VALUES('44', '1844 Corralitos Ave', 'California', '69', '93401', '8053059134');
