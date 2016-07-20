ALTER TABLE cb_books ADD CONSTRAINT edition_number CHECK (edition > 0);

UPDATE mg_customers SET address_id = 1 WHERE address_id IS NULL;
ALTER TABLE mg_customers ADD CONSTRAINT f_key_empty CHECK (address_id IS NOT NULL);

ALTER TABLE dv_address ADD CONSTRAINT address_null CHECK (address IS NOT NULL);
