-- first session
BEGIN TRANSACTION;	--Session1;	
BEGIN TRANSACTION; --Session2;	
SELECT * FROM pizzeria WHERE name = 'Pizza Hut'; --Session1;	
UPDATE pizzeria SET rating = 3.6 WHERE name = 'Pizza Hut'; --Session2;
COMMIT WORK; --Session2;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut'; --Session1;	
COMMIT WORK;		--Session1;	
SELECT * FROM pizzeria;	--Session1;	
SELECT * FROM pizzeria WHERE name = 'Pizza hut'; --Session2;	

										

