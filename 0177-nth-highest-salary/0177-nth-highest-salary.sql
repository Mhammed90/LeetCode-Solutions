CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    RETURN (
        /* Write your T-SQL query statement below. */
  select Salary
from (
    select distinct Salary, DENSE_RANK() over (order by Salary desc) as DR
    from Employee
) as Result
where DR = @N
    );
END