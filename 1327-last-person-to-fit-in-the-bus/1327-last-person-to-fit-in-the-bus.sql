/* Write your T-SQL query statement below */
 


 select top (1)  person_name 
   from ( 
       select  person_name,
        sum(weight) over (order by turn) as total_weight
      from Queue
   ) as temp  
   where total_weight<=1000 
   order by total_weight desc 
