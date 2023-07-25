WITH currencies AS (
    SELECT DISTINCT ON (name) name, id, rate_to_usd
    FROM currency
    ORDER BY name, updated DESC
), balances AS (
    SELECT user_id,
           type,
           SUM(money) AS volume,
           currency_id
    FROM balance
    GROUP BY user_id, type,currency_id
    ORDER BY 1
)
SELECT
    COALESCE(u.name, 'not defined') AS name,
    COALESCE(u.lastname, 'not defined') AS lastname,
    balances.type,
    balances.volume AS volume,
    COALESCE(currencies.name, 'not defined') AS currency_name,
    COALESCE(currencies.rate_to_usd, 1) AS last_rate_to_usd,
    (volume * COALESCE(currencies.rate_to_usd, 1)) AS total_volume_in_usd
FROM balances
LEFT JOIN "user" u ON u.id = balances.user_id
LEFT JOIN currencies ON currencies.id = balances.currency_id
GROUP BY user_id, type, currency_id, u.name, u.lastname, balances.volume, last_rate_to_usd, currencies.name, currencies.rate_to_usd
ORDER BY 1 DESC, 2, 3;
