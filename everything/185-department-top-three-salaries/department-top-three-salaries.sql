select name as Department, employee, salary
from
(
    select d.name as name, e.name as employee, salary,
           dense_rank() over(
               partition by d.id
               order by salary desc
           ) as rnk
    from department d
    join employee e
    on d.id = e.departmentId
) x
where rnk <= 3;