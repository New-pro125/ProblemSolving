-- Write your PostgreSQL query statement below
WITH CTE AS (
    SELECT o.buyer_id, COUNT(*) as cnt
    FROM Users u JOIN Orders o ON u.user_id = o.buyer_id
    WHERE o.order_date BETWEEN '2019-01-01' and '2019-12-31'
    GROUP BY o.buyer_id
)

SELECT u.user_id as buyer_id, u.join_date, coalesce(c.cnt,0) as orders_in_2019
FROM Users u LEFT OUTER JOIN CTE c on u.user_id = c.buyer_id