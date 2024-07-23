# Write your MySQL query statement below
with t1 as (Select users_id from Users
where banned = 'NO')

, t2 as(Select status, request_at,
Case when status in ('cancelled_by_driver','cancelled_by_client') then 1
else 0
end as flag
from Trips
where client_id in(Select users_id from t1)
and driver_id in(Select users_id from t1)
)

Select request_at as Day,
round(sum(flag)/count(*), 2)as 'Cancellation Rate'
from t2
Where request_at between '2013-10-01' and '2013-10-03'
group by request_at
