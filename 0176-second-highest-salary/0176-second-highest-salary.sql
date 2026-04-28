SELECT MAX(salary) as SecondHighestSalary FROM 
(SELECT DISTINCT salary, DENSE_RANK() OVER(ORDER BY salary DESC) as num FROM Employee) as x 
WHERE x.num = 2