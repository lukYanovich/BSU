-- Вывести раюотников 1 отдела с зарплатой выше средней по отделу
select *
from employees
where department_id = 1
group by employee_id
having salary >= (select avg(salary) from employees where department_id = 1)