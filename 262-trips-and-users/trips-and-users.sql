/* Write your T-SQL query statement below */

with cte as (select request_at as Day, 
sum( case 
when status is not null then 1 else 0 end) as total , 
sum(case
when status= 'completed' then 1 else 0 end) as completed
   from trips
where client_id  not in (
    select users_id from users 
    where banned='Yes'
)
and driver_id  not in (
    select users_id from users 
    where banned='Yes'
)
and request_at in ('2013-10-01', '2013-10-02', '2013-10-03')
group by request_at)
select Day, round((cast(total as decimal (10,2))-cast(completed as decimal (10,2)))/cast(total as decimal(10,2)),2) as 'Cancellation Rate' from cte