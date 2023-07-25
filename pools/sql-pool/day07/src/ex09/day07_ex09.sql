SELECT address,
    round(
        MAX(age) - (round(MIN(age), 2) / round(MAX(age), 2)),
        2
    )::FLOAT AS formula,
    round(AVG(age), 2)::FLOAT AS average,
    round((max(age) - min(age) / max(age::numeric)), 2) > round(avg(age), 2) as comparison
FROM person
GROUP BY address
ORDER BY 1