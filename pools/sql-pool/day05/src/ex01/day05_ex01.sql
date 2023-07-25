SET enable_indexscan = ON;
SET enable_seqscan = OFF;
EXPLAIN ANALYSE
SELECT menu.pizza_name,
    pz.name
FROM menu
    JOIN pizzeria pz ON menu.pizzeria_id = pz.id