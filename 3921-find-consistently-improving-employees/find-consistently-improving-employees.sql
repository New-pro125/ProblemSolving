-- Write your PostgreSQL query statement below
with cte as (
  SELECT * , dense_rank() over (partition by employee_id order by review_date desc) as rnk
  FROM performance_reviews
  WHERE employee_id IN (
    SELECT employee_id
    FROM performance_reviews
    GROUP BY employee_id
    HAVING COUNT(review_date) >= 3
  )
),cte3 as (
  SELECT c.employee_id, c.review_date, c.rating
  ,lag(c.rating,1) over (PARTITION BY employee_id
               ORDER BY review_date desc) as l_rating, lag(c.rating,2) over (PARTITION BY employee_id
               ORDER BY review_date desc) as ll_rating
  FROM cte c 
  where rnk <=3
)

select c.employee_id, e.name, (c.ll_rating - c.rating) as improvement_score
FROM cte3 c
JOIN Employees e
ON c.employee_id = e.employee_id
WHERE c.ll_rating > c.l_rating and c.l_rating > c.rating
ORDER BY (c.ll_rating - c.rating) desc, e.name