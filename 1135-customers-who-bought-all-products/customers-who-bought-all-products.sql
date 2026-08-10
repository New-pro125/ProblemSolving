-- Write your PostgreSQL query statement below
WITH CTE AS
(SELECT customer_id, COUNT(DISTINCT product_key)
FROM Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) IN (
    SELECT COUNT(DISTINCT product_key) 
    FROM Product
))
SELECT customer_id 
FROM CTE;