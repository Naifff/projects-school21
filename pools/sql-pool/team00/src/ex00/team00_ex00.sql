create table cities (
    id bigint primary key,
    name varchar not null
);
insert into cities
values (1, 'a');
insert into cities
values (2, 'b');
insert into cities
values (3, 'c');
insert into cities
values (4, 'd');
create table nodes (
    id bigint primary key,
    point1 bigint not null,
    point2 bigint not null,
    constraint fk_order_point1 foreign key (point1) references cities(id),
    constraint fk_order_point2 foreign key (point2) references cities(id),
    cost numeric not null default 1
);
insert into nodes
values (1, 1, 2, 10);
insert into nodes
values (2, 2, 1, 10);
insert into nodes
values (3, 2, 3, 35);
insert into nodes
values (4, 3, 2, 35);
insert into nodes
values (5, 3, 4, 30);
insert into nodes
values (6, 4, 3, 30);
insert into nodes
values (7, 1, 3, 15);
insert into nodes
values (8, 3, 1, 15);
insert into nodes
values (9, 1, 4, 20);
insert into nodes
values (10, 4, 1, 20);
insert into nodes
values (11, 2, 4, 25);
insert into nodes
values (12, 4, 2, 25);
CREATE VIEW v_tour AS (
    WITH RECURSIVE tour AS (
        SELECT CONCAT(c1.name, ', ', c2.name) AS name_tour,
            point1,
            point2,
            cost,
            cost AS summ,
            1 AS iter
        FROM nodes
            JOIN cities AS c1 ON nodes.point1 = c1.id
            JOIN cities AS c2 ON nodes.point2 = c2.id
        WHERE point1 = 1
        UNION ALL
        SELECT CONCAT(tour.name_tour, ', ', cities.name) AS name_tour,
            nodes.point1,
            nodes.point2,
            nodes.cost,
            tour.summ + nodes.cost AS summ,
            iter + 1
        FROM nodes
            JOIN tour ON nodes.point1 = tour.point2
            JOIN cities ON nodes.point2 = cities.id
        WHERE name_tour NOT LIKE '%' || cities.name || '%'
    )
    SELECT *
    FROM tour
);
CREATE VIEW v_done_tour AS (
    SELECT v_tour.summ + ns.cost AS total_cost,
        CONCAT('{', v_tour.name_tour, ', ', cities.name, '}') AS tour
    FROM v_tour
        JOIN (
            SELECT *
            FROM nodes
            WHERE point1 = 1
        ) AS ns ON v_tour.point2 = ns.point2
        JOIN cities ON ns.point1 = cities.id
    WHERE LENGTH (name_tour) = 10
);
SELECT *
FROM v_done_tour
WHERE total_cost = (
        SELECT MIN(total_cost)
        FROM v_done_tour
    )
ORDER BY 1,
    2;