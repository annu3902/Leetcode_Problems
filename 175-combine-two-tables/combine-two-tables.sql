# Write your MySQL query statement below
Select firstName, lastName, city, state
From Person as p1
Left Join Address as p2
On p1.personId = p2.personId;