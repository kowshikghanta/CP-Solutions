# Write your MySQL query statement below
select distinct p1.email from person p1 where p1.email in (select p2.email from person p2 where p1.id <> p2.id)