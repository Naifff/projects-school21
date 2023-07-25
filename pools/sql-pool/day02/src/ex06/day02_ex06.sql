SELECT menu.pizza_name,
       pizzeria.name as pizzeria_name
FROM person_order
JOIN person ON person_order.person_id = person.id
JOIN menu ON person_order.menu_id = menu.id
JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
WHERE person.name = 'Denis'
    or person.name = 'Anna'
ORDER BY pizza_name,
         pizzeria_name