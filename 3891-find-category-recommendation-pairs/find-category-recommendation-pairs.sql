-- Write your PostgreSQL query statement below
with cte as (
    SELECT p1.* , p2.category
    FROM ProductPurchases p1 
    LEFT OUTER JOIN ProductInfo p2
    ON p1.product_id = p2.product_id
)

SELECT  c1.category as category1 , c2.category as category2 , COUNT(distinct c1.user_id) as customer_count
FROM cte c1
INNER JOIN cte c2
ON c1.user_id = c2.user_id
AND c1.category < c2.category
GROUP BY c1.category, c2.category
HAVING COUNT(DISTINCT c1.user_id) >= 3
ORDER BY customer_count desc, category1, category2;