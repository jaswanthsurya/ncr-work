use ncr
 CREATE TABLE emp(
  empno    int,
  ename    nVARCHAR(10),
  job      nVARCHAR(9),
  mgr      INT,
  hiredate DATE,
  sal      DECIMAL(7,2),
  comm     DECIMAL(7,2),
  deptno   INT,
  CONSTRAINT pk_emp PRIMARY KEY (empno),
  constraint fk_deptno foreign key (deptno) references dept(deptno)
);