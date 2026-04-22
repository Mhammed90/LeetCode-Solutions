/* Write your T-SQL query statement below */


SELECT 
    product_id,
    year AS first_year,
    quantity,
    price
FROM Sales s
WHERE year = (
    SELECT MIN(year)
    FROM Sales
    WHERE product_id = s.product_id
);


