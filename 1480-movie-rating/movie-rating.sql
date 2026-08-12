-- Write your PostgreSQL query statement below
with cte as (
    SELECT u.name,count(m.user_id) over(partition by u.user_id order by u.name) as num
    FROM Users u Join MovieRating m on m.user_id = u.user_id
    order by u.name
), cte2 as (
    SELECT m.title, AVG(mr.rating) over (partition by mr.movie_id order by m.title) as avg_rating
    FROM Movies m Join MovieRating mr on m.movie_id = mr.movie_id 
    where created_at between '2020-02-01' and '2020-02-29'
    order by m.title
)

(SELECT name as results 
FROM cte 
order by num desc 
limit 1)
UNION ALL
(SELECT title as results 
FROM cte2 
order by avg_rating desc
limit 1);