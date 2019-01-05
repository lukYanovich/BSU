-- Вывести минимальную и максимальную зарплату
select max(salary)
from employees 
union
select min(salary)
from employees