# Write your MySQL query statement below
SELECT t1.name
FROM Employee AS t1
JOIN Employee AS t2
ON t1.id = t2.managerId
GROUP BY t1.id, t1.name
HAVING COUNT(t2.id) >= 5;

