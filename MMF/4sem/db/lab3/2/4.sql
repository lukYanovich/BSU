-- Вывести отделы по убыванию количества средств в месяце
select * 
from departments
group by max_amount desc