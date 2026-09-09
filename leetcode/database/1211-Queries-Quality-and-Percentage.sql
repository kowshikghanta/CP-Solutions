# Write your MySQL query statement below
select q.query_name as query_name, 
    round (
        sum(q.rating / q.position) / count(*), 2
    ) as quality,
    round (
        (count(case when q.rating < 3 then 1 end)) * 100 / count(*), 2
    ) as poor_query_percentage
from queries q group by q.query_name;