# Write your MySQL query statement below
SELECT e1.name
FROM Employee e1
JOIN Employee e2 
on e1.id = e2.managerID
GROUP BY e2.managerID
HAVING COUNT(e2.managerID) >= 5