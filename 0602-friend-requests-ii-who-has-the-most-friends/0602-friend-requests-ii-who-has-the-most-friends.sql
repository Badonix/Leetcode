SELECT TOP 1 coalesce(t1.id, t2.id) as id, (coalesce(t1.cnt, 0) + coalesce(t2.cnt, 0)) AS num FROM
(SELECT requester_id as id, COUNT(*) as cnt FROM RequestAccepted
GROUP BY requester_id) as t1 FULL OUTER JOIN
(SELECT accepter_id as id, COUNT(*) as cnt FROM RequestAccepted
GROUP BY accepter_id) as t2 ON t1.id = t2.id
ORDER BY coalesce(t1.cnt, 0) + coalesce(t2.cnt, 0) DESC