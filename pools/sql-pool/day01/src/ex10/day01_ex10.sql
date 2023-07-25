SELECT person.name AS person_name,
	menu.pizza_name AS pizza_name,

				(SELECT name
					FROM pizzeria
					WHERE menu.pizzeria_id = id) AS pizzeria_name
FROM person_order
INNER JOIN person ON person_order.person_id = person.id
INNER JOIN menu ON person_order.menu_id = menu.id
ORDER BY person_name,
	pizza_name,
	pizzeria_name