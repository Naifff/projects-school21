SELECT pizzeria.name,
    COUNT(*) AS count_of_orders,
    round(AVG(price), 2)::FLOAT AS average_price,
    MAX(price) AS max_price,
    MIN(price) AS min_price
FROM person_order
    JOIN menu ON menu.id = person_order.menu_id
    JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
GROUP BY pizzeria.name
ORDER BY pizzeria.name