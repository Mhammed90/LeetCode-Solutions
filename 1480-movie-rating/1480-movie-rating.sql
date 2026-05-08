/* Write your T-SQL query statement below */
 
SELECT *
FROM (
    SELECT TOP(1) name AS results
    FROM (
        SELECT U.user_id,
               COUNT(R.user_id) AS cnt,
               U.name
        FROM MovieRating R
        JOIN Users U
            ON R.user_id = U.user_id
        GROUP BY U.user_id, U.name
    ) AS T
    ORDER BY cnt DESC, name ASC
) A

UNION ALL

SELECT *
FROM (
    SELECT TOP(1) movieName AS results
    FROM (
        SELECT title AS movieName,
               AVG(cast(rating as float)) AS average_rating
        FROM MovieRating mr
        JOIN Movies m
            ON mr.movie_id = m.movie_id
        WHERE MONTH(created_at) = 2
         AND YEAR(created_at) = 2020
        GROUP BY m.movie_id, title
    ) AS rating_group
    ORDER BY average_rating DESC, movieName ASC
) B;