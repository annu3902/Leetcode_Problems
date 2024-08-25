# Write your MySQL query statement below


select e1.name
from Employee e1
Join Employee e2
ON e2.managerId = e1.id
GROUP BY e2.managerID
HAVING COUNT(e2.managerID) >= 5 
