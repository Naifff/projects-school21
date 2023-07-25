INSERT INTO person_order (id, person_id, menu_id, order_date)
SELECT vt,
    p.id,
    (
        SELECT id
        FROM menu
        WHERE pizza_name = 'greek pizza'
    ),
    '2022-02-25'
FROM generate_series(
        (
            SELECT (max(id) + 1)
            FROM person_order
        ),
        (
            SELECT max(id) + 1
            FROM person
        ) + (
            SELECT (max(id))
            FROM person_order
        )
    ) as vt
    JOIN person p ON p.id + (
        SELECT (max(id) + 1)
        FROM person_order
    ) = vt