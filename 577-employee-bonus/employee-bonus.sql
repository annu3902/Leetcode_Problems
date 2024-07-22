# Write your MySQL query statement below
Select name, bonus
From Employee as e
Left join Bonus as b
On e.empId = b.empId 
Where bonus < 1000 
or bonus is null;

