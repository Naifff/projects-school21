(
    SELECT pizzeria.name,
        count(person_id) AS count,
        'order' AS action_type
    FROM person_order
        JOIN menu ON menu.id = person_order.menu_id
        JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
    GROUP BY pizzeria.name
    ORDER BY count DESC
    LIMIT 3
)
UNION ALL
(
    SELECT pizzeria.name,
        COUNT(person_id) AS count,
        'visit' AS action_type
    FROM person_visits
        JOIN pizzeria ON person_visits.pizzeria_id = pizzeria.id
    GROUP BY pizzeria.name
    ORDER BY count DESC
    LIMIT 3
)
ORDER BY action_type