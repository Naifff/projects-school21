SELECT DISTINCT pizzeria.name AS pizzeria_name,
                pizzeria.rating
FROM person_visits
RIGHT JOIN pizzeria ON person_visits.pizzeria_id = pizzeria.id
WHERE person_visits.pizzeria_id IS NULL