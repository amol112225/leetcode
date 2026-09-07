# Write your MySQL query statement below
SELECT t1.machine_id, round(avg(t2.timestamp-t1.timestamp),3) as processing_time 
FROM Activity as t1
JOIN Activity as t2
on t1.machine_id = t2.machine_id
and t1.process_id = t2.process_id
-- and t1.timestamp < t2.timestamp
and t1.activity_type='start'
and t2.activity_type = 'end'
GROUP BY t1.machine_id;