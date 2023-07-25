CREATE OR REPLACE FUNCTION fnc_person_visits_and_eats_on_date(
        IN pperson varchar DEFAULT 'Dmitriy',
        IN pprice numeric DEFAULT 500,
        IN pdate date DEFAULT '2022-01-08'
    ) RETURNS TABLE (name varchar) AS $$
SELECT piz.name AS pizzeria_name
FROM person_visits pv
    JOIN person p ON pv.person_id = p.id
    JOIN menu m ON pv.pizzeria_id = m.pizzeria_id
    JOIN pizzeria piz ON pv.pizzeria_id = piz.id
WHERE p.name = pperson
    AND m.price < pprice
    AND pv.visit_date = pdate;
END;
$$ LANGUAGE sql;
select *
from fnc_person_visits_and_eats_on_date(pprice := 800);
select *
from fnc_person_visits_and_eats_on_date(
        pperson := 'Anna',
        pprice := 1300,
        pdate := '2022-01-01'
    );