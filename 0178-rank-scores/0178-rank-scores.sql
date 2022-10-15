# Write your MySQL query statement below
select scores.score, count(s.score) as 'rank' from scores, (select distinct score from scores) s where scores.score<=s.score group by scores.id order by scores.score desc;
