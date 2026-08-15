WITH cte AS (
    SELECT *,
           LAG(result) OVER (
               PARTITION BY patient_id
               ORDER BY test_date
           ) AS prev_result
    FROM covid_tests
),
first_positive AS (
    SELECT patient_id,
           MIN(test_date) AS first_positive_date
    FROM covid_tests
    WHERE result = 'Positive'
    GROUP BY patient_id
),
recovery AS (
    SELECT c.patient_id,
           MIN(c.test_date) AS recovery_date
    FROM cte c
    JOIN first_positive fp
      ON c.patient_id = fp.patient_id
    WHERE c.result = 'Negative'
      AND c.test_date > fp.first_positive_date
    GROUP BY c.patient_id
)
SELECT r.patient_id,
       p.patient_name,
       p.age,
       r.recovery_date - fp.first_positive_date AS recovery_time
FROM recovery r
JOIN first_positive fp
  ON r.patient_id = fp.patient_id
JOIN patients p
  ON r.patient_id = p.patient_id
ORDER BY recovery_time, p.patient_name;