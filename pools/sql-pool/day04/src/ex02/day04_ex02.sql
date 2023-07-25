CREATE VIEW v_generated_dates AS
SELECT gs::date AS generated_date
FROM generate_series (
        '2022-01-01'::timestamp,
        '2022-01-31'::timestamp,
        '1 day'::interval
    ) AS gs
ORDER BY generated_date;