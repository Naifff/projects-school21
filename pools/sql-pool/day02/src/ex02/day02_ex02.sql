SELECT CASE
           WHEN person.name IS NULL THEN '-'
           ELSE person.name
       END person_name,
       pv.visit_date,
       CASE
           WHEN pizzeria.name IS NULL THEN '-'
           ELSE pizzeria.name
       END pizzeria_name
FROM
    (SELECT *
     FROM person_visits
     WHERE visit_date BETWEEN '2022-01-01' AND '2022-01-03') AS pv
FULL OUTER JOIN person ON pv.person_id = person.id
FULL OUTER JOIN pizzeria ON pv.pizzeria_id = pizzeria.id
ORDER BY person_name,
         visit_date,
         pizzeria_name