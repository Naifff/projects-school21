INSERT INTO person_order
VALUES (
        (
            SELECT max(id)
            FROM person_order
        ) + 1,
        (
            SELECT id
            FROM person
            WHERE name = 'Denis'
        ),
        (
            SELECT id
            FROM menu
            WHERE pizza_name = 'sicilian pizza'
        ),
        '2022-02-24'
    );

INSERT INTO person_order
VALUES (
        (
            SELECT max(id)
            FROM person_order
        ) + 1,
        (
            SELECT id
            FROM person
            WHERE name = 'Irina'
        ),
        (
            SELECT id
            FROM menu
            WHERE pizza_name = 'sicilian pizza'
        ),
        '2022-02-24'
    );