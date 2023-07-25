SELECT name,
    pv.count_of_visits
FROM person
    JOIN (
        SELECT person_id,
            COUNT(person_id) AS count_of_visits
        FROM person_visits
        GROUP BY person_id
    ) AS pv ON person.id = pv.person_id
ORDER BY count_of_visits DESC
LIMIT 4