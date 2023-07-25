SELECT person_order.order_date, 
    pv.name || ' (age:' || pv.age || ')' AS person_information
FROM person_order
NATURAL JOIN (SELECT id as person_id, age, name FROM person) as pv
ORDER BY order_date, person_information