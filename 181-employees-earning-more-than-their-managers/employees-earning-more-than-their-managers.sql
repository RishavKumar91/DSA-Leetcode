
select e.name as employee
from employee e
left join employee m
on m.id  = e.managerId where m.salary < e.salary