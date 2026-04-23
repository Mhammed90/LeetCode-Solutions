/* Write your T-SQL query statement below */



select E1.employee_id as employee_id ,E1.name as name,count(E2.reports_to) as reports_count ,round(avg(cast(E2.age as float)),0) as average_age 
from Employees E1 join Employees E2  
on E1.employee_id=E2.reports_to
group by  E1.employee_id,E1.name
order by employee_id