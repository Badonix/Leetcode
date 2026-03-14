/* Write your T-SQL query statement below */
SELECT s.name FROM SalesPerson as s
WHERE sales_id NOT IN (
    SELECT o.sales_id FROM Orders as o
    LEFT JOIN Company as c
    ON o.com_id = c.com_id 
    WHERE c.name = 'RED'
)
