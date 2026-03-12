/* Write your T-SQL query statement below */
SELECT firstName, lastName, city, [state] FROM
Person as p LEFT JOIN 
[Address] as a ON a.personId = p.personId