WITH visits_and_ordres AS ((
    SELECT pizzeria.name,
        count(person_id) AS count
    FROM person_order
        JOIN menu ON menu.id = person_order.menu_id
        JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
    GROUP BY pizzeria.name
    ORDER BY count DESC
)
UNION ALL
(
    SELECT pizzeria.name,
        COUNT(person_id) AS count
    FROM person_visits
        JOIN pizzeria ON person_visits.pizzeria_id = pizzeria.id
    GROUP BY pizzeria.name
    ORDER BY count DESC
))

SELECT name, SUM(count) AS total_count FROM visits_and_ordres
GROUP BY name
ORDER BY total_count DESC, name