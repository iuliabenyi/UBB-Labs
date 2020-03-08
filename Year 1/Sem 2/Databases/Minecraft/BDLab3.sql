--a. modify the type of a column;
go 
create or alter procedure do1
as
begin
	alter table Enchantments
	alter column TestColumn int
end
go
--execute do1

go 
create or alter procedure undo1
as
begin
	alter table Enchantments
	alter column TestColumn varchar(50)
end
go
--execute undo1



--b. add / remove a column;
go
create or alter procedure do2
as
begin
	alter table Players
	add TestColumnPlayer int;
end
go
--execute do2

go
create or alter procedure undo2
as
begin
	alter table Players
	drop column TestColumnPlayer;
end
go
--execute undo2



--c. add / remove a DEFAULT constraint;
go
create or alter procedure do3
as
begin
	alter table Achievements add TestConstraint int,
	constraint DF_Achievement_TestConstraint default 1 for TestConstraint;
end
go
--execute do3 -- wut

go
create or alter procedure undo3
as
begin
	alter table Achievements drop
	constraint DF_Achievement_TestConstraint,
	column TestConstraint;
end
go
--execute undo3



--d. add / remove a primary key;
go
create or alter procedure do4
as
begin
	create table testTable(Number int not null);
	alter table testTable
	add constraint PKNumber primary key clustered(Number);
end
go
--execute do4

go
create or alter procedure undo4
as
begin
	alter table testTable
drop constraint PKNumber
drop table testTable
end
go
--execute undo4



--e. add / remove a candidate key;
go
create or alter procedure do5
as
begin
	alter table Items
	add constraint UQ_Items_id_name  unique(Iid, Name)
end
go
--execute do5 --wut

go
create or alter procedure undo5
as
begin
	alter table Items 
	drop constraint UQ_Items_id_name
end
go
--execute undo5



--f. add / remove a foreign key;
go
create or alter procedure do6
as
begin
	alter table Structures
	add TestFK int;	

	alter table Structures
	add constraint Structures_TestFK foreign key(TestFK)
	references Players(Pid);
end
go
--execute do6

go
create or alter procedure undo6
as
begin
	alter table Structures
	drop constraint Structures_TestFK;

	alter table Structures 
	drop column TestFK;
end
go
--execute undo6

--g. create / remove a table.
go
create or alter procedure do7
as
begin
	create table TestTableG(
			testID int primary key,
			testCol varchar(50)
			);
end
go
--execute do7

go
create or alter procedure undo7
as
begin 
	drop table if exists TestTableG
end
go
--execute undo7 




--Create a new table that holds the current version of the database schema. 

drop table if exists DBVersion
create table DBVersion
	(
		id int identity (1, 1) not null,
		currVersion int,
		constraint PK_version_ID primary key clustered(id)
	)

insert into DBVersion values(0);



--Write another stored procedure that receives as a parameter a version number and brings the database to that version.
go
create or alter procedure TakeMeToVersion
	@versionTo int
as
begin
	declare @versionFrom int 
	set @versionFrom = (select V.currVersion from DBVersion V)
	declare @query varchar(2000)

	if @versionTo <= 7 and @versionTo >= 0
		if @versionTo > @versionFrom
		begin 
			while @versionTo > @versionFrom
			begin
				set @versionFrom = @versionFrom + 1
				set @query = 'do' + CAST(@versionFrom as varchar(5))
				exec @query
			end
		end
		else
		begin
			while @versionTo < @versionFrom
			begin
				if @versionFrom != 0
				begin
					set @query = 'undo' + CAST(@versionFrom as varchar(5))
					exec @query
				end
				set @versionFrom = @versionFrom - 1
			end
		end
		else
		begin
			print 'version has to be <= 7 and >= 0'
			return 
		end

		update DBVersion
		set currVersion = @versionTo
end
go 

exec TakeMeToVersion 1;
select * from DBVersion

