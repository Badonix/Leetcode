/* Write your T-SQL query statement below */
SELECT a.name as "Employee" FROM 
Employee as a join Employee as b
ON a.managerId = b.id 
WHERE a.salary > b.salary