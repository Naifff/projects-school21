BEGIN; --Session1;
UPDATE pizzeria set rating = 5 WHERE name = 'Pizza Hut'; --Session1;
SELECT * FROM pizzeria WHERE name  = 'Pizza Hut'; --Session2;
SELECT * FROM pizzeria SET rating = 5 WHERE name = 'Pizza Hut'; --Session1;
COMMIT WORK; --Session1;
SELECT * FROM pizzeria WHERE name = 'Pizza Hut'; --Session2;


