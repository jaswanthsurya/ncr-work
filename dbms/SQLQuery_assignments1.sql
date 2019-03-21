/*insert into ncrwork values(1,'jash','sw');
select * from ncrwork;

delete ncrWork;

create table jash(
id int,
name varchar(20),
role varchar(20),
constraint jash_pk primary key(id)
);

drop table jash
drop table ncrWork

create table DeptDetails(
Deptname varchar(20),
deptno int,
constraint DeptDetails_pk primary key(deptno)
);



create table masterDetails(
id int,
name varchar(20),
address varchar(50),
deptno int,
faculty varchar(10),
constraint masterDetails_pk primary key(id),
constraint masterDetails_fk foreign key(deptno) references DeptDetails(deptno)
);*/

insert into DeptDetails values('narradept',10)
insert into masterDetails values(1,'jash','chintal',10,'narra')

select * from masterDetails
select * from DeptDetails

insert into masterDetails values(2,'surya','chintal',10,'narra')

insert into DeptDetails values('somadept',20)
insert into DeptDetails values('akhildept',30)

insert into masterDetails values(3,'sai','jntu',20,'narra')
insert into masterDetails values(4,'kumar','kukatpally',20,'soma')
insert into masterDetails values(5,'p','balnagar',30,'akhil')

alter table masterDetails add salary int;

update masterDetails set salary=1000 where deptno=10;

update masterDetails set salary=1500 where deptno=20;

update masterDetails set salary=2000 where deptno=30;

select * from masterDetails


select deptno,max(salary) as maximumsalary,avg(salary) as averagesalary from masterDetails group by(deptno) having(deptno=10);


alter table masterDetails add commission int

update masterDetails set commission=100 where deptno=10

update masterDetails set commission=150 where deptno=20


select deptno,name,salary+commission as totalsal from masterDetails

select deptno,max(salary)+max(commission) as maxtotalsalary from masterDetails group by(deptno)

select deptno,max(salary)+max(isnull(commission,0)) as maxtotalsalary from masterDetails group by(deptno)


select name,salary,deptno from masterDetails where salary=(select max(salary) from masterDetails)


/*1)*/select name,salary from masterDetails where salary>=1000 and salary<=2000


/*2*/alter table masterDetails add DepartmentName varchar(10)

select * from masterDetails

update masterDetails set DepartmentName='narra' where deptno=10

update masterDetails set DepartmentName='soma' where deptno=20

update masterDetails set DepartmentName='akhil' where deptno=30

select name,deptno,DepartmentName from masterDetails order by(deptno)

alter table masterDetails add JobType varchar(20)

update masterDetails set JobType='clerk' where deptno=10

update masterDetails set JobType='supervisor' where deptno=20

select * from masterDetails

update masterDetails set JobType='manager' where deptno=30

select * from masterDetails

/*3)*/select distinct(JobType),deptno from masterDetails

/*4)*/ select name,id from masterDetails where deptno in(10,20) order by(name)

/*5*/select name,JobType from masterDetails where deptno=20

/*6*/ insert into masterDetails values(6,'hhhai','miyapur',30,'akhil',2000,10,'akhil','manager')
 insert into masterDetails values(7,'jaswanth','hydernagar',30,'akhil',2000,10,'akhil','clerk')
select * from masterDetails
 
select name,deptno,DepartmentName from masterDetails where name like '%hh%' or name like '%th%'

/*7)*/ select * from masterDetails
insert into masterDetails values(8,'prathik','hydernagar',10,'akhil',2000,10,'akhil','manager')
insert into masterDetails values(9,'yaswanth','hydernagar',20,'soma',200,10,'soma','manager')
insert into DeptDetails values('prathikdept',40)
insert into masterDetails values(10,'rajkumar','hydernagar',40,'prathik',2000,150,'prathik','designer')
select name,deptno,DepartmentName from masterDetails where JobType!='manager' 

select name,deptno,DepartmentName from masterDetails where deptno in((select deptno from masterDetails where JobType='manager')) and JobType!='manager'
  

/*8)*/ select name, salary+isnull(commission,0) as TotalSalary from masterDetails


/*9)*/select name, (salary+isnull(commission,0))*12 as AnnualSalary from masterDetails where commission > salary and JobType='sales' order by salary,name
select * from masterDetails

/*10)*/select concat (name,' is a ', JobType) as Profession, salary+salary*0.15 as HikeSalary from masterDetails

/*11)*/ update masterDetails set JobType='sales person' where JobType='sales'
select* from masterDetails

/*12)*/select JobType,max(salary) as MaxSalary,min(salary) as MinSalary from masterDetails group by(JobType)

/*13)*/ select count(name) as numberOfManagers from masterDetails where JobType='manager'

/*14)*/select JobType,avg(salary) as averagesalary, sum(salary+isnull(commission,0)) as TotalRemunaration from masterDetails group by(JobType)

/*15)*/ select JobType,max(salary)-min(salary) as DiffereneceBetweenSalaries from masterDetails group by(JobType)

/*16)*/select deptno from masterDetails group by(deptno) having(count(name)>2)

/*17)*/ select id from masterDetails group by(id) having(count(id)>1)

/*18a)*/ select min(salary) as MinimumSalaryOfEmployeesInEachDepartment,deptno from masterDetails 
		where deptno in(select deptno from masterDetails where JobType='manager')
		and name in(select name from masterDetails where salary>1000)
		and JobType!='manager' group by(deptno)
select * from masterDetails

/*19a)*/select name,Deptname from masterDetails m,DeptDetails d where m.deptno=d.deptno order by(Deptname)

/*20a)*/ select m.name,m.deptno,d.Deptname from masterDetails m,DeptDetails d where m.deptno=d.deptno

/*21a)*/ select m.name,m.address,m.deptno,d.Deptname from masterDetails m,DeptDetails d 
		where m.deptno=d.deptno and m.salary>1500

/*22a)*/alter table DeptDetails add grade int

select * from DeptDetails

update DeptDetails set grade=1 where deptno=10
update DeptDetails set grade=2 where deptno=20
update DeptDetails set grade=3 where deptno=30
update DeptDetails set grade=4 where deptno=40

select m.name,d.Deptname,m.JobType,m.deptno,d.grade from masterDetails m,DeptDetails d 
where m.deptno=d.deptno and d.grade=3

/*23a)*/select name,address,salary,commission,deptno from masterDetails where address='Dullas'
select * from masterDetails

/*24a)*/ select m.name,m.JobType,m.salary,d.grade,d.Deptname from masterDetails m,DeptDetails d 
		where m.deptno=d.deptno and m.JobType!='clerk' order by(m.salary) desc



/*18)*/select * from emp
select * from dept
select * from salgrade
select min(sal) as minimumsalary,deptno from emp where mgr in(select mgr from emp where mgr is not NULL) and job!='manager' group by(deptno)


/*19)*/select e.ename,d.dname from emp e,dept d where d.deptno=e.deptno order by(dname)

/*20)*/select e.ename,e.deptno,d.dname from emp e,dept d where d.deptno=e.deptno

/*21)*/select e.ename,d.loc,d.dname from emp e,dept d where d.deptno=e.deptno and e.sal>1500 order by(dname)

/*22)*/select e.ename,e.sal from emp e,salgrade s where s.grade=3 and e.sal>losal and e.sal<hisal

/*23)*/select e.ename,d.loc,d.dname from emp e,dept d where d.deptno=e.deptno and d.loc='dallas' order by(dname)

/*24)*/select e.ename,e.job,e.sal,d.dname,s.grade from emp e,dept d,salgrade s 
	   where e.deptno=d.deptno and s.grade in(select s.grade from salgrade 
	   where e.sal>=s.losal and e.sal<=s.hisal) and e.job!='clerk' order by(e.sal) desc
/*25)*/ select ename,job,sal,deptno from emp where (sal*12)=36000 or job='clerk'

/*26)*/ select deptno from dept where deptno not in(select deptno from emp)

/*27)*/ select max(sal) as maximumsalary,job from emp group by(job) order by(max(sal)) desc

/*28)*/ 


/*cursors...................................................*/


use ncr;
DECLARE
@tempSal int,
@tempComm int,
@TotalSal int,
@commissionhigher int,
@salaryhigher    int

DECLARE TestCursor cursor for select sal,isnull(comm,0) as comm from emp where deptno=20

OPEN TestCursor 
		SET @TotalSal=0
		SET @salaryhigher=0
		SET @commissionhigher=0
		while(@@FETCH_STATUS=0)
		begin
			FETCH NEXT FROM TestCursor into @tempSal,@tempComm
			print @tempSal
			print @tempComm
			SET @TotalSal = @TotalSal+ @tempSal
			if(@tempSal>2000)
				SET @salaryhigher=@salaryhigher+1;
			if(@tempComm>@tempSal)
				SET @commissionhigher=@commissionhigher+1;
		end
		print @TotalSal
		print @salaryhigher
		print @commissionhigher

CLOSE TestCursor
DEALLOCATE TestCursor