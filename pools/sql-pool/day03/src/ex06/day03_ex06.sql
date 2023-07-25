WITH menu1 AS (
    SELECT *
    FROM menu
),
menu2 AS (
    SELECT *
    FROM menu
)
SELECT menu1.pizza_name,
    pizzeria1.name AS pizzeria_name_1,
    pizzeria2.name AS pizzeria_name_2,
    menu1.price
FROM menu1
    JOIN menu2 ON menu1.pizza_name = menu2.pizza_name
    AND menu1.price = menu2.price
    JOIN pizzeria AS pizzeria1 ON menu1.pizzeria_id = pizzeria1.id
    JOIN pizzeria AS pizzeria2 ON menu2.pizzeria_id = pizzeria2.id
WHERE menu1.pizzeria_id > menu2.pizzeria_id
ORDER BY 1