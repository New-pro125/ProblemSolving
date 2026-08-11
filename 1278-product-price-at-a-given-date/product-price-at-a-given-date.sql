-- Write your PostgreSQL query statement below

with CTE AS (
    SELECT p.product_id, max(p.change_date) as last_change_date
    FROM Products p 
    where p.change_date <= '2019-08-16'
    group by p.product_id
), cte2 as (
    SELECT distinct p.product_id, c.last_change_date FROM 
    Products p left outer join CTE c on c.product_id = p.product_id
)
SELECT c.product_id , coalesce(p.new_price,10) as price
FROM cte2 c left outer join products p on c.last_change_date = p.change_date and c.product_id = p.product_id