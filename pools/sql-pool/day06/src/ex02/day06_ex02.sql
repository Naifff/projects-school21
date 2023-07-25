SELECT person.name AS person_name,
    menu.pizza_name,
    menu.price,
    (menu.price / 100 * (100 - person_discounts.discount))::FLOAT AS discount_price,
    pizzeria.name as pizzeria_name
FROM person_order
    JOIN menu ON person_order.menu_id = menu.id
    JOIN person_discounts ON menu.pizzeria_id = person_discounts.pizzeria_id
    AND person_order.person_id = person_discounts.person_id
    JOIN person ON person_order.person_id = person.id
    JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
ORDER BY person.name,
    menu.pizza_name