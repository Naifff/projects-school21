SELECT person1.name AS person_name1,
	   person2.name AS person_name2,
	   person1.address AS common_address
FROM person AS person1
INNER JOIN person AS person2
ON person1.address = person2.address
WHERE person1.id > person2.id
ORDER BY 1, 2, 3;