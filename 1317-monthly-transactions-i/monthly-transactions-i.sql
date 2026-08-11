-- Write your PostgreSQL query statement below

SELECT to_char(t.trans_date, 'YYYY-MM') as month, country, count(t.id) as trans_count, sum(case when state = 'approved' then 1 else 0 end) as approved_count, sum(t.amount) as trans_total_amount, sum(case when state = 'approved' then t.amount else 0 end) as approved_total_amount
    FROM Transactions t 
    group by country, to_char(t.trans_date, 'YYYY-MM')