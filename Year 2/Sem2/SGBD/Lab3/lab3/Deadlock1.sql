begin tran 
update Books 
set title='deadlock Books Transaction 1' 
where id=61

waitfor delay '00:00:10' 
update Authors
set name='deadlock Authors Transaction 1' 
where id=56
commit tran

-------------------------------------------------------------------------
begin tran 
update Books 
set title='deadlock Books Transaction 1' 
where id=61
waitfor delay '00:00:10' 
update Authors 
set name='deadlock Authors Transaction 1' 
where id=56
commit tran