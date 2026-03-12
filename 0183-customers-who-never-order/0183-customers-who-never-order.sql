/* Write your T-SQL query statement below */
SELECT [name] as Customers FROM
Customers as c 
LEFT JOIN Orders as o
ON c.id = o.customerId
WHERE o.id IS NULL