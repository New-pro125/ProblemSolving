-- Write your PostgreSQL query statement below
With cte as(
    SELECT s.* , p.category,(
        CASE 
            WHEN EXTRACT(MONTH FROM s.sale_date) IN (12, 1, 2) THEN 'Winter'
            WHEN EXTRACT(MONTH FROM s.sale_date) IN (3, 4, 5) THEN 'Spring'
            WHEN EXTRACT(MONTH FROM s.sale_date) IN (6, 7, 8) THEN 'Summer'
            ELSE 'Fall'
        end
    ) AS Season
    FROM SALES s
    LEFT OUTER JOIN Products p
    ON s.product_id = p.product_id
), cte2 as (
    SELECT season, category, SUM(quantity) as total_quantity, SUM(quantity * price)::numeric as total_revenue
    FROM cte
    GROUP BY Season, category
), cte3 as (
SELECT *, dense_rank() over (partition by season order by total_quantity desc, total_revenue desc) as rnk
FROM cte2
)

SELECT season, category, total_quantity, total_revenue
FROM cte3
where rnk = 1
order by season