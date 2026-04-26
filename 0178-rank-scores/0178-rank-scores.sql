/* Write your T-SQL query statement below */


select score,Dense_rank() over(order by score desc) 
as rank from scores 