/* Write your T-SQL query statement below */
SELECT id FROM Weather as w
WHERE w.temperature > (SELECT temperature FROM Weather WHERE recordDate = DATEADD(day, -1, w.recordDate))