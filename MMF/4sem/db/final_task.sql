#-----------------------------------------------------------------------------------
#recovery

insert into locations(
	street_address, 
    postal_code, 
    city, 
    state_province,
    country_id
)
select distinct r.street_address,
	r.postal_code,
	r.city,
	r.state_province,
	r.country_id
from report r
where 
	r.city is not null and	
	r.country_id is not null;
           

insert into departments(
	department_name, 
    location_id
)
select distinct department_name, 
	l.location_id
from report r
	left join locations l on
		r.country_id = l.country_id and
        r.city = l.city
where department_name is not null;


insert into employees(
	first_name,
    last_name,
    email,
    phone_number,
    hire_date,
    job_id,
    salary,
    commission_pct,
    department_id
)
select distinct FIRST_NAME,
	LAST_NAME,
	EMAIL,
	PHONE_NUMBER,
	HIRE_DATE,
	JOB_ID,
	SALARY,
	COMMISSION_PCT,
    d.department_id
from report r
	left join departments d on
		r.DEPARTMENT_NAME = d.department_name
where r.LAST_NAME is not null;


update departments d
	left join(
		select employee_id, 
			first_name, 
			last_name, 
			department_id
		from employees
		where (first_name, last_name) in (
			select r.DEPARTMENT_MANAGER_FIRST_NAME, 
				r.DEPARTMENT_MANAGER_LAST_NAME
			from report r
			)
		) e on
		d.department_id = e.department_id
	set d.manager_id = e.employee_id;


update employees t1
	left join(
		select t1.employee_id employee_id,
			t2.employee_id manager_id
		from report r
			left join employees t1 on
				r.FIRST_NAME = t1.first_name and
				r.LAST_NAME = t1.last_name
			left join employees t2 on
				r.MANAGER_FIRST_NAME = t2.first_name and
				r.MANAGER_LAST_NAME = t2.last_name
		) t2 on
		t1.employee_id = t2.employee_id
	set t1.manager_id = t2.manager_id;


#-----------------------------------------------------------------------------------
#task

update employees 
	set salary =  salary + 100
where (first_name, last_name) not in(
	select r.MANAGER_FIRST_NAME, 
		r.MANAGER_LAST_NAME 
	from report r
	where employees.first_name = r.MANAGER_FIRST_NAME and 
		employees.last_name = r.MANAGER_LAST_NAME
);


update employees
	set email = concat(left(first_name,5), left(last_name,5));


update employees 
	set salary = salary * 1.1
where department_id in(
	select *
    from(
		select department_id
        from employees
		where department_id is not null
		group by department_id
		having count(department_id) < 10
    ) t
)
            
            