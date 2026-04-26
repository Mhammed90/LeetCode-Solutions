/* Write your T-SQL query statement below */


select 
    p.product_id,
    coalesce(
        (
            select top(1) new_price
            from products p2
            where p2.product_id = p.product_id
              and p2.change_date <= '2019-08-16'
            order by p2.change_date desc
        ), 
        10
    ) as price
from 
    (select distinct product_id from products) p;