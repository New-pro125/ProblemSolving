-- Write your PostgreSQL query statement below
WITH cte AS (
  SELECT s1.student_id, s1.subject, s1.score as first_score, s2.score as next_score, DENSE_RANK() OVER(PARTITION BY s1.student_id, s1.subject ORDER BY s1.exam_date, s2.exam_date desc ) as rnk
  FROM Scores s1 
  LEFT OUTER JOIN Scores s2
  ON s1.student_id = s2.student_id 
  AND s1.subject = s2.subject 
  AND s1.exam_date < s2.exam_date
  WHERE s2.exam_date IS NOT NULL)

SELECT student_id, subject, first_score, next_score as latest_score 
FROM cte
WHERE rnk = 1
AND next_score > first_score
order by student_id, subject;