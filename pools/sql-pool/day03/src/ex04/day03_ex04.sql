WITH female AS (
    SELECT pizzeria.name
    FROM person_order
        JOIN menu ON person_order.menu_id = menu.id
        JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
        JOIN person ON person_order.person_id = person.id
    WHERE person.gender = 'female'
),
male AS (
    SELECT pizzeria.name
    FROM person_order
        JOIN menu ON person_order.menu_id = menu.id
        JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
        JOIN person ON person_order.person_id = person.id
    WHERE person.gender = 'male'
),
only_female AS (
    SELECT name
    FROM female
    EXCEPT
    SELECT name
    FROM male
),
only_male AS (
    SELECT name
    FROM male
    EXCEPT
    SELECT name
    FROM female
)
SELECT name AS pizzeria_name
FROM only_female
UNION ALL
SELECT name
FROM only_male
ORDER BY 1;