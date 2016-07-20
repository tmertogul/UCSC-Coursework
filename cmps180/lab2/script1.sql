DROP TABLE cb_authors, cb_books, cb_customers, dv_address, dv_customer, dv_film, mg_customers CASCADE;
DROP TYPE mpaa_rating;
DROP SEQUENCE mg_customers_seq;

CREATE TABLE dv_customer (
   customer_id INT PRIMARY KEY, 
   first_name VARCHAR(50),
   last_name VARCHAR(50),
   email VARCHAR(50),
   address_id INT,
   active BOOLEAN
);

CREATE TABLE dv_address (
   address_id INT PRIMARY KEY, 
   address VARCHAR(50),
   address2 VARCHAR(50),
   district VARCHAR(50),
   city_id INT,
   postal_code VARCHAR(50),
   phone VARCHAR(50) 
);

CREATE TYPE mpaa_rating AS ENUM (
   'G',
   'PG',
   'PG-13',
   'R',
   'NC-17'
);

CREATE TABLE dv_film (
   film_id INT PRIMARY KEY,
   title VARCHAR(50),
   description TEXT,
   length SMALLINT,
   rating mpaa_rating,
   release_year SMALLINT
);

CREATE TABLE cb_customers (
   last_name VARCHAR(50),
   first_name VARCHAR(50)
);

CREATE TABLE cb_books (
   title VARCHAR(50),
   author_id INT,
   edition SMALLINT,
   publisher VARCHAR(50)
);

CREATE TABLE cb_authors (
   author_id INT PRIMARY KEY,
   first_name VARCHAR(50),
   last_name VARCHAR(50)
);

CREATE TABLE mg_customers (
   customer_id INT PRIMARY KEY,
   first_name VARCHAR(50),
   last_name VARCHAR(50),
   email VARCHAR(50),
   address_id INT,
   active BOOLEAN
);
