/* Write your T-SQL query statement below */
SELECT product_name, year, price FROM Sales as s
LEFT JOIN Product p 
ON p.product_id = s.product_id
