-- Write your PostgreSQL query statement below
WITH CTE AS (
    SELECT customer_id, min(order_date) as first_order, count(*) Over() as n
    FROM Delivery
    GROUP BY customer_id
), CTE2 AS (
    SELECT count(*) as immediate_cnt
    FROM CTE c join Delivery d ON  d.customer_id = c.customer_id
    where c.first_order = d.customer_pref_delivery_date
)

SELECT ROUND( ((select immediate_cnt from cte2)::numeric/ (select distinct n from cte)) * 100,2) as immediate_percentage FROM cte2;