SELECT COALESCE(u.name, 'not defined') AS name,
    COALESCE(u.lastname, 'not defined') AS lastname,
    c.name AS currency_name,
    (money * rate_to_usd) AS currency_in_usd
FROM balance b
    LEFT JOIN "user" u on b.user_id = u.id
    JOIN currency c ON c.id = b.currency_id
WHERE c.updated = (
        SELECT CASE
                WHEN b.updated < (
                    SELECT MIN(updated)
                    FROM currency
                    WHERE id = b.currency_id
                ) THEN (
                    SELECT MIN(updated)
                    FROM currency
                    WHERE id = b.currency_id
                        AND b.updated < updated
                )
                ELSE (
                    SELECT MAX(updated)
                    FROM currency
                    WHERE id = b.currency_id
                        AND b.updated > updated
                )
            END
    )
ORDER BY name DESC,
    lastname,
    currency_name;

    
select t1.name,
    t1.lastname,
    currency_name,
    money * rate_to_usd as currency_in_usd
from (
        select coalesce(u.name, 'not defined') as name,
            coalesce(u.lastname, 'not defined') as lastname,
            c.name as currency_name,
            money,
            coalesce(
                (
                    select rate_to_usd
                    from currency c
                    where b.currency_id = c.id
                        and c.updated < b.updated
                    order by c.updated desc
                    limit 1
                ), (
                    select rate_to_usd
                    from currency c
                    where b.currency_id = c.id
                        and c.updated > b.updated
                    order by c.updated asc
                    limit 1
                )
            ) as rate_to_usd
        from balance b
            inner join (
                select c.id,
                    c.name
                from currency c
                group by c.id,
                    c.name
            ) as c on c.id = b.currency_id
            left join "user" u on u.id = b.user_id
    ) as t1
order by 1 desc,
    2,
    3;