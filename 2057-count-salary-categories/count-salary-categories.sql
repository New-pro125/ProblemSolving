-- Write your PostgreSQL query statement below
select 'Low Salary' as category,
SUM(case when income < 20000 then 1 else 0 end ) as accounts_count
from Accounts
UNION
select 'Average Salary' as category,
SUM(case when income BETWEEN 20000 and 50000 then 1 else 0 end ) as accounts_count
from Accounts
UNIon
select 'High Salary' as category,
SUM(case when income > 50000 then 1 else 0 end ) as accounts_count
from Accounts