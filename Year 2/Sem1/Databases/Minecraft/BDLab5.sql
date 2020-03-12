create database Lab5_IE
go
use Minecraft
go
drop table if exists Customers
CREATE TABLE Customers(-- Ta
Cid INT PRIMARY KEY IDENTITY, -- aid
Name VARCHAR(50),
Age INT, -- a2
AppId INT UNIQUE
)

insert into Customers values ('name1', 1, 1)
insert into Customers values ('name2', 2, 2)
insert into Customers values ('name3', 3, 3)
insert into Customers values ('name4', 4, 4)
insert into Customers values ('name5', 5, 5)

drop table if exists Applications
CREATE TABLE Applications(-- Tb
Aid INT PRIMARY KEY IDENTITY, -- bid
PName VARCHAR(50),
Descriptionn VARCHAR(50),
Price INT-- b2
)

insert into Applications values ('name1', 'descr1', 1)
insert into Applications values ('name2', 'descr2', 2)
insert into Applications values ('name3', 'descr3', 3)
insert into Applications values ('name4', 'descr4', 4)
insert into Applications values ('name5', 'descr5', 5)

drop table if exists AC 
CREATE TABLE AC(-- Tc
ACid INT PRIMARY KEY IDENTITY, -- cid
Cid INT FOREIGN KEY REFERENCES Customers(Cid), -- aid
Aid INT FOREIGN KEY REFERENCES Applications(Aid) -- bid
)

insert into AC values (1, 1)
insert into AC values (2, 2)
insert into AC values (3, 3)
insert into AC values (4, 4)
insert into AC values (5, 5)

select * from Customers
select * from Applications
select * from AC

--a)
--clustered index, primary key
select * from Customers order by Cid

--nonclustered index, unique key
select * from Customers order by Age 

--nonclustered index, delete if exists
if exists (select name from sys.indexes where name = N'N_idx_Name_Name')
	drop index [N_idx_Name_Name] on Customers
go

--non-clustered index creation
create nonclustered index N_idx_Name_Name on Customers(Name);
go

--clustered index scan
select Name from Customers where Name = 'name1' order by Cid

--non-clustered index seek
select * from Customers where Name = 'name1' order by Name


--check indexes from Leaders
select i2.name, i1.user_scans, i1.user_seeks, i1.user_updates, i1.last_user_scan, i1.last_user_seek,
 i1.last_user_update from sys.dm_db_index_usage_stats i1
 inner join sys.indexes i2 on i1.index_id = i2.index_id
 where i1.object_id = OBJECT_ID('Customers') and i1.object_id = i2.object_id

 --b)
 
select * from Applications where price = 1

if exists (select name from sys.indexes where name = N'N_idx_Price')
	drop index N_idx_Price on Applications
go

create nonclustered index N_idx_Price on Applications(Price);
go

select * from Applications where Price = 1

set nocount on;
go
set showplan_all on;
go
--
select Price from Applications where Price between 1 and 4;
go
--
set showplan_all off;
go
--always clustered even though there is a non-clustered index

--c)

go
create view [Test]
as
select a.Price, a.PName, c.Name from Applications a 
	inner join AC ac on a.Aid = ac.Aid
	inner join Customers c on c.Cid = ac.Cid
	where a.Price >= 1 and  a.Price <= 4
go

select * from [Test]

exec sp_helpindex 'Applications'
exec sp_helpindex 'Customers'