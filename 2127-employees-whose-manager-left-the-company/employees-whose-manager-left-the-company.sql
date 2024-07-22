# Write your MySQL query statement below
Select employee_id 
from Employees
where salary < 30000
and manager_id not in
(Select employee_id 
from Employees)
Order by employee_id