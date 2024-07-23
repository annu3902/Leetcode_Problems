# Write your MySQL query statement below
Select product_name, year, price
FROM Sales as s
inner join Product as p
On s.product_id = p.product_id;
