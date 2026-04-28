/* Write your T-SQL query statement below */
SELECT ConsecutiveNums FROM
(SELECT DISTINCT num as ConsecutiveNums,
LAG(num) OVER (ORDER BY id) as lag,
LEAD(num) OVER (ORDER BY id) as lead
FROM Logs
) as x
WHERE x.lag = x.lead AND x.lead = x.ConsecutiveNums
