use lab3;

#dep_id, emp_amount, dep_name, max_emp
insert into departments values
	#(1, 200, "отдел тестировки", 5),
    (2, 210, "отдел маркетинга", 15),
    (3, 1500, "отдел разработок", 4),
    (4, 400, "отдел цро", 2),
    (5, 150, "отдел юстиции", 4);
    
#con_id, con_name, con_desc, dep_id
insert into consumptions values
	(1, "техническое обслуживание", null, 1),
    (2, "покупка по", null, 3),
    (3, "покупка бумаги", null, 2),
    (4, "техническое обслуживание", null, 4),
    (5, "покупка по", null, 3),
    (6, "корпоратив", null, 2),
    (7, "корпоратив", null, 5);
    
#emp_id, emp_name, dep_id, emp_age, emp_salary
insert into employees values
	(1, "Ирина", 1, 25, 300),
    (3, "Сергей", 2, 31, 500),
    (5, "Олег", 3, 22, 300),
    (7, "Александр", 4, 30, 300),
    (10, "Марк", 5, 30, 500);