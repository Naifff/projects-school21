WITH missing_dates AS
    ( SELECT gs::date AS missing_date
     FROM generate_series ('2022-01-01'::timestamp, '2022-01-10'::timestamp, '1 day'::interval) AS gs),
     ps AS
    ( SELECT *
     FROM person_visits
     WHERE person_id = 1
         OR person_id = 2 )
SELECT missing_date
FROM missing_dates
LEFT JOIN ps ON DATE(missing_date) = DATE(ps.visit_date)
WHERE visit_date IS NULL;