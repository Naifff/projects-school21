SELECT menu.pizza_name,
    menu.price,
    pizzeria.name AS pizzeria_name
FROM menu
    RIGHT JOIN (
        SELECT id as menu_id
        FROM menu
        EXCEPT
        SELECT menu_id
        FROM person_order
    ) AS po ON menu.id = po.menu_id
    JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
ORDER BY 1,
    2