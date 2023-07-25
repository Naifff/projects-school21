(SELECT
	person_id
FROM person_order
WHERE DATE(order_date) = '2022-01-07')
EXCEPT ALL
(SELECT
	person_id
FROM person_visits
WHERE DATE(visit_date) = '2022-01-07')
