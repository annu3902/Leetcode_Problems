# Write your MySQL query statement below
Select author_id as id
from Views
Where author_id = viewer_id
Union
Select author_id
from Views
Where author_id = viewer_id
order by id
