-- Вывести данные работников и их отделов
select * 
from departments, employees
where employees.department_id = departments.department_id