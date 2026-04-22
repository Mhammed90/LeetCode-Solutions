/* Write your T-SQL query statement below */



select class as class
from Courses 
group by class
having  count(student)>=5 
