# Write your MySQL query statement below
SELECT t1.user_id, round(avg(if(t2.action="confirmed",1,0)),2) as confirmation_rate 
FROM Signups t1
LEFT JOIN Confirmations as t2
ON t1.user_id = t2.user_id
GROUP BY t1.user_id
