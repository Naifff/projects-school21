
       (SELECT name as object_name
        FROM person
        ORDER BY object_name)
UNION ALL
       (SELECT pizza_name as object_name
        FROM menu
        ORDER BY object_name)