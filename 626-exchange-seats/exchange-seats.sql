-- Write your PostgreSQL query statement below
with cte as (
  SELECT t.*, LAG(t.student) OVER (), LEAD(t.student) OVER () 
  FROM Seat t
)
SELECT id, (
  CASE 
    WHEN id % 2 = 1 and lead is null then student
    WHEN id % 2 = 1 then lead
  ELSE LAG
  END 
) AS student FROM CTE;
