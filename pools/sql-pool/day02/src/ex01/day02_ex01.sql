SELECT gs::date AS missing_date
FROM generate_series ('2022-01-01'::timestamp , '2022-01-10'::timestamp , '1 day'::interval) AS gs
LEFT JOIN
        (SELECT *
         FROM person_visits
         WHERE person_id = 1
                 OR person_id = 2)AS pv ON DATE(gs::date) = DATE(pv.visit_date)
WHERE visit_date IS NULL;