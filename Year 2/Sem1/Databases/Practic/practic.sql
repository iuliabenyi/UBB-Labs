create database Practic
go 
use Practic
go
drop table if exists Currency
create table Currency(
	curid int primary key identity,
	cname varchar(50),
	country varchar(50)
)

drop table if exists Exchange
create table Exchange (
	eid int primary key identity,
	eaddress varchar(50)
)

drop table if exists CE
create table CE(
	curid int foreign key references Currency(curid),
	eid int foreign key references Exchange(eid),
	sellrate int,
	buyrate int,
	constraint pk_CE primary key(curid, eid)
)

drop table if exists Customer
create table Customer(
	cusid int primary key identity,
	cname varchar(50)
)

drop table if exists Transactions
create table Transactions(
	tid int primary key identity(1,1),
	ttype varchar(50),
	tvalue int,
	curid int foreign key references Currency(curid),
	cusid int foreign key references Customer(cusid)
)

go
create procedure addCurr @curid int, @eid int, @sell int, @buy int
as
	declare @nr int;
	set @nr = 0;
	select @nr = count(*) from CE where eid = @eid and curid = @curid

	if (@nr <> 0)
	begin
		update CE
		set sellrate = @sell, buyrate=@buy
		where eid = @eid and curid = @curid
	end
	else begin
		insert into CE values (@eid,@curid,@sell,@buy)
	end
go

--insert
select * from CE
exec addCurr 1, 2, 20, 30
select * from CE


go
create or alter view V1
as

select C.cname
from Customer C
where count(Transactions.curid) = 1
/*
select cname from Customer C 
inner join
Transactions T on C.cusid = T.cusid
group by cname having count(*) = (select min(curid) from Transactions)*/
go

select * from V1