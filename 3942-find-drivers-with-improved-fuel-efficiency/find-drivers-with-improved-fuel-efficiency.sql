-- Write your PostgreSQL query statement below
WITH first_half as (
    SELECT distinct driver_id, avg(distance_km/fuel_consumed::numeric) over (partition by driver_id) as fha
    FROM trips
    WHERE EXTRACT(MONTH FROM trip_date) < 7
), second_half as (
    SELECT distinct driver_id, avg(distance_km/fuel_consumed::numeric) over (partition by driver_id) as sha
    FROM trips
    WHERE EXTRACT(MONTH FROM trip_date) >= 7
)
SELECT fh.driver_id, d.driver_name , ROUND(fh.fha,2) as first_half_avg ,ROUND(sh.sha,2) as second_half_avg, ROUND(sh.sha - fh.fha,2) as efficiency_improvement 
FROM first_half fh
JOIN second_half sh
ON fh.driver_id = sh.driver_id
JOIN drivers d
ON fh.driver_id = d.driver_id
WHERE fh.fha < sh.sha
ORDER BY 5 desc, 2
