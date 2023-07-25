SELECT action_date,

    (SELECT name
     FROM person
     WHERE pv.person_id = person.id) as person_name
FROM
    (SELECT order_date as action_date,
            person_id as person_id
     FROM person_order INTERSECT SELECT visit_date,
                                        person_id
     FROM person_visits) AS pv
ORDER BY action_date,
         person_name DESC