insert into Books values ('Book for Deadlock', 'english') 
insert into Authors values ('Author for Deadlock') 
select * from Books 
select * from Authors

begin tran
update Authors 
set name='deadlock Authors Transaction 2' 
where id=1 
-- this transaction has exclusively lock on table Authors 
waitfor delay '00:00:10' 
update Books 
set title='deadlock Books Transaction 2' 
where id=8 
commit tran

select * from Books 
select * from Authors

------------------------------------------------------------------------
SET DEADLOCK_PRIORITY HIGH
begin tran 
update Authors 
set name='deadlock Authors Transaction 2' 
where id=56
waitfor delay '00:00:10' 
update Books 
set title='deadlock Books Transaction 2' 
where id=61
commit tran

select * from Books 
select * from Authors
