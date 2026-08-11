-- Write your PostgreSQL query statement below
WITH CTE AS (
    SELECT *, SUM(weight) OVER (ORDER BY turn ) as total
    FROM Queue
)

SELECT person_name
FROM CTE
WHERE total <= 1000
ORDER BY total desc
LIMIT 1;