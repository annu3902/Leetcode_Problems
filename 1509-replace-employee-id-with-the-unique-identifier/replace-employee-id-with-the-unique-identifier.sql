# Write your MySQL query statement below
Select unique_id, name
from Employees as t1
Left Join EmployeeUNI as t2
On t1.id = t2.id;