SELECT
    (SELECT name
     FROM person
     WHERE person_order.person_id = person.id ) AS NAME
FROM person_order
WHERE (menu_id = 13
       or menu_id = 14
       or menu_id = 18)
    AND (DATE(order_date) = '2022-01-07')