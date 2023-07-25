SELECT person.name
FROM person_order
JOIN person ON person_order.person_id = person.id
JOIN menu ON person_order.menu_id = menu.id
WHERE (person.address = 'Moscow'
       OR person.address = 'Samara')
    AND person.gender = 'male'
    AND (menu.pizza_name = 'mushroom pizza'
         OR menu.pizza_name = 'pepperoni pizza')
ORDER BY person.name DESC