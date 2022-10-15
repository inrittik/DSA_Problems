# Write your MySQL query statement below
select D.name as Department, E.name as Employee, E.salary from Department D, Employee E, (select departmentId, max(salary) as max from employee group by departmentId) T where D.id = T.departmentId and E.salary = T.max and E.departmentId = D.id;
