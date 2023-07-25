WITH dmitriy AS (
    SELECT id
    FROM person
    WHERE name = 'Dmitriy'
),
visits_dmitriy AS (
    SELECT pizzeria_id
    FROM person_visits
    WHERE person_id IN (
            SELECT *
            FROM dmitriy
        )
)
INSERT INTO person_visits (id, person_id, pizzeria_id, visit_date)
VALUES (
        (
            SELECT MAX(id) + 1
            FROM person_visits
        ),
        (
            SELECT *
            FROM dmitriy
        ),
        (
            SELECT menu.pizzeria_id
            FROM menu
                LEFT JOIN visits_dmitriy ON menu.pizzeria_id = visits_dmitriy.pizzeria_id
            WHERE visits_dmitriy.pizzeria_id IS NULL
                AND price < 800
            LIMIT 1
        ), '2022-01-08'
    );
REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;
SELECT *
FROM mv_dmitriy_visits_and_eats;