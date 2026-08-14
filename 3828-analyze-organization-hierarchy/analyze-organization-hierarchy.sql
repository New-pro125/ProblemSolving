-- Write your PostgreSQL query statement below
with recursive cte as (
  SELECT *, 1 as level from Employees where manager_id is null
  union all 
  select e.*, c.level + 1  as level from cte c join employees e on e.manager_id = c.employee_id
), cte2 AS (
  SELECT employee_id, employee_id as manager_id
  FROM Employees 
  UNION ALL 
  SELECT e.employee_id, c2.manager_id
  FROM cte2 c2
  JOIN Employees e 
  ON c2.employee_id = e.manager_id
), cte3 as (
  SELECT  c1.employee_id, c1.employee_name,c1.level, c2.manager_id, c2.employee_id as eid ,e.salary
  FROM cte c1
  JOIN cte2 c2 ON c1.employee_id = c2.manager_id
  JOIN Employees e ON c2.employee_id = e.employee_id
)
SELECT employee_id, employee_name, level, count(CASE WHEN employee_id <> eid then eid else null end) as team_size, sum(salary) as budget
FROM cte3 
GROUP BY employee_id, employee_name, level
ORDER BY level, budget desc, employee_name;