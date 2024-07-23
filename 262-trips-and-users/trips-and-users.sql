# Write your MySQL query statement below
with temp as (Select users_id from Users
            Where banned = 'No')
            -- Created or extracted the required imformation and store it in temp table
,temp2 as (   
    Select request_at, status,
    case when status in ('cancelled_by_client', 'cancelled_by_driver') then 1 
    else 0 
    end as flag
    from Trips
    Where client_id in(Select users_id from temp)
    and driver_id in(Select users_id from temp)
)

Select request_at as Day, round((sum(flag)*1.0) / count(*), 2) as 'Cancellation Rate' 
from temp2
Where request_at >= '2013-10-01' and request_at <= '2013-10-03'
group by request_at






