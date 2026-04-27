/* Write your T-SQL query statement below */



select T.DName as Department ,T.EName as Employee,T.salary   as Salary
from  (
    select d.name as DName ,e.name as EName,e.salary as salary, dense_rank() over( partition by  e.departmentId order by e.salary desc)  as DR
    from Employee e,Department d 
    where d.id=e.departmentId 
)  as T
where DR<4