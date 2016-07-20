DROP TABLE dv_customer CASCADE;
DROP TABLE dv_address CASCADE;
DROP TABLE dv_film CASCADE;
DROP TABLE cb_customers CASCADE;
DROP TABLE cb_authors CASCADE;
DROP TABLE cb_books CASCADE;
DROP TABLE mg_customers CASCADE;
DROP TYPE mpaa_rating;
DROP SEQUENCE mg_customers_seq;

CREATE TYPE mpaa_rating AS ENUM (
    'G',
    'PG',
    'PG-13',
    'R',
    'NC-17'
);

CREATE TABLE dv_customer (
	customer_id integer
	, first_name varchar(50)
	, last_name varchar(50)
	, email varchar(50)
	, address_id integer
	, active boolean
);

CREATE TABLE dv_address (
	address_id integer
	, address varchar(50)
	, address2 varchar(50)
	, district varchar(50)
	, city_id integer
	, postal_code varchar(50)
	, phone varchar (50)
);

CREATE TABLE dv_film (
	film_id integer
	, title varchar(50)
	, description text
	, length smallint
	, rating mpaa_rating
	, release_year smallint
);

CREATE TABLE cb_customers (
	last_name varchar(50)
	, first_name varchar(50)
);

CREATE TABLE cb_books (
	title varchar(50)
	, author_id integer
	, edition smallint
	, publisher varchar(50)
);

CREATE TABLE cb_authors (
	author_id integer
	, first_name varchar(50)
	, last_name varchar(50)
);

CREATE TABLE mg_customers (
	customer_id integer
	, first_name varchar(50)
	, last_name varchar(50)
	, email varchar(50)
	, address_id integer
	, active boolean
);

\copy dv_customer FROM 'dv_customer.data'
\copy dv_address FROM 'dv_address.data'
\copy dv_film FROM 'dv_film.data'
\copy cb_customers FROM 'cb_customers.data'
\copy cb_books FROM 'cb_books.data'
\copy cb_authors FROM 'cb_authors.data'

-- 3.3.1 
INSERT INTO mg_customers
SELECT * FROM dv_customer;

-- 3.3.2
CREATE SEQUENCE mg_customers_seq START 600;
ALTER TABLE mg_customers
ALTER COLUMN customer_id
SET DEFAULT NEXTVAL('mg_customers_seq');

-- 3.3.3
INSERT INTO mg_customers (first_name, last_name)
SELECT first_name, last_name
FROM cb_customers
EXCEPT
SELECT first_name, last_name
FROM dv_customer;

DROP TABLE dv_customer;
DROP TABLE cb_customers;

-- Lab 3
ALTER TABLE mg_customers ADD PRIMARY KEY (customer_id);

ALTER TABLE dv_address ADD PRIMARY KEY (address_id);

ALTER TABLE dv_film ADD PRIMARY KEY (film_id);

ALTER TABLE cb_books ADD PRIMARY KEY (title, author_id, edition);

ALTER TABLE cb_authors ADD PRIMARY KEY (author_id);

ALTER TABLE mg_customers
ADD FOREIGN KEY (address_id)
REFERENCES dv_address(address_id);

ALTER TABLE cb_books
ADD FOREIGN KEY (author_id)
REFERENCES cb_authors(author_id);

ALTER TABLE cb_books
ADD CONSTRAINT edition_number CHECK (edition > 0);

UPDATE mg_customers
SET address_id = (select address_id from dv_address order by random() limit 1)
WHERE address_id IS NULL;

ALTER TABLE mg_customers
ALTER COLUMN address_id SET NOT NULL;

ALTER TABLE dv_address
ALTER COLUMN address SET NOT NULL;

-- For lab 4
CREATE SEQUENCE dv_film_seq START 1001;
ALTER TABLE dv_film
ALTER COLUMN film_id 
SET DEFAULT NEXTVAL('dv_film_seq');


