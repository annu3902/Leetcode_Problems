# Write your MySQL query statement below
SELECT name
FROM Customer
WHERE COALESCE(referee_id, name, -1) != 2;