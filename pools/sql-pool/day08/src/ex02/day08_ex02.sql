BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ;	--Session1;	
BEGIN TRANSACTION ISOLATION LEVEL REPEATABLE READ; --Session2;		
SELECT * FROM pizzeria WHERE name = 'Pizza Hut'; --Session1;	
SELECT * FROM pizzeria WHERE name = 'Pizza Hut'; --Session2;									--3
UPDATE pizzeria SET rating = 4 WHERE name = 'Pizza Hut'; --Session1;	
UPDATE pizzeria SET rating = 3.6 WHERE name = 'Pizza Hut'; --Session2;	
COMMIT WORK; --Session1;	
COMMIT WORK; --Session2;											
SELECT * FROM pizzeria; --Session1;
SELECT * FROM pizzeria; --Session2;