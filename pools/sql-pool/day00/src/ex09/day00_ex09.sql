SELECT
    (SELECT name
     FROM person
     WHERE person_id = person.id) AS person_name,

    (SELECT name
     FROM pizzeria
     WHERE pizzeria_id = pizzeria.id) AS pizzeria_name
FROM
    (SELECT person_id,
            pizzeria_id
     FROM person_visits
     WHERE DATE(visit_date) BETWEEN '2022-01-07' AND '2022-01-09') AS pv
ORDER BY person_name,
         pizzeria_name DESC