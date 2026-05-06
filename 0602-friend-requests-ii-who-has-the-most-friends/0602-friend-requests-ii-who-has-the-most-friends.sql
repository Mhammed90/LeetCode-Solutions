/* Write your T-SQL query statement below */

 
select top(1) i as id  ,count(i) as num  from 
( 
select requester_id as i from  
RequestAccepted  
union all 
select accepter_id as i from 
RequestAccepted
) as t  
group by i
order by count(i) desc

