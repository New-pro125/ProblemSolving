-- Write your PostgreSQL query statement below
SELECT s.user_id, ROUND((SUM(case when m.action = 'confirmed' then 1 else 0 end) / count(*)::numeric), 2) as confirmation_rate
FROM Signups s LEFT OUTER JOIN Confirmations m ON  s.user_id = m.user_id
GROUP BY s.user_id; 