SELECT pv.name, COUNT(pv.pizzeria_id) AS count_of_visits FROM
(SELECT DISTINCT pizzeria_id, person.name FROM person_visits
JOIN person ON person_visits.person_id = person.id) AS pv
GROUP BY pv.name
HAVING  COUNT(pv.pizzeria_id) > 3