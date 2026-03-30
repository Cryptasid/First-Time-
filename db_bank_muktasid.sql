SELECT now(), user(), database();
--show database;
--create database db_bank_muktasid;
--show database;
use db_bank_muktasid;
--show tables;
--SELECT now(), user(), database();
--drop database db_bank_muktasid;

create TABLE tbl_customer(
	customerID INT PRIMARY KEY,
	cs_name VARCHAR(60),
	cs_street VARCHAR(60),
	cs_city VARCHAR(60)
);
show tables;
create TABLE tbl_branch(
	branchCode INT PRIMARY KEY,
	br_name VARCHAR(60),
	br_street VARCHAR(60),
	br_city VARCHAR(60),
	br_assets INT
);

show tables;
--insert into tbl_customer values(025,'muktasid','subidbazar','sylhet');
insert into tbl_branch values(067,'Subidbazar Branch','subidbazar','sylhet',50000);
select* from tbl_customer;
select* from tbl_branch;
desc tbl_branch;
show create table tbl_branch;
