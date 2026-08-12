-- Write your PostgreSQL query statement below
with cte as (
    SELECT distinct visited_on, sum(amount) over(partition by visited_on) as amount, dense_rank() over( order by visited_on) as rnk
    from Customer
), cte2 as (
    SELECT visited_on, sum(amount) over( order by visited_on rows between 6 preceding and current row) as amount,rnk
    from cte
)

SELECT visited_on, amount, (round(amount::numeric / 7,2)) as average_amount 
from cte2 
where rnk > 6
