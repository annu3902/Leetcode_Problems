# Write your MySQL query statement below
SELECT v.customer_id, COUNT(v.customer_id) as count_no_trans
FROM Visits v

LEFT JOIN Transactions t
USING(visit_id)
WHERE t.transaction_id is null
GROUP BY v.customer_id
-- HAVING t.transaction_id is null
-- Having COUNT(t.transaction_id is null)

