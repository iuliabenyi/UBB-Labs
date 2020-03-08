--pk no fk: Players
--pk and fk: Achievements
--2 pks: PA

drop table if exists TestTables
create table TestTables(
		TestID int not null,
		TableID int not null,
		NoOfRows int not null,
		Position int not null,
		constraint PK_TestTables primary key(TestID, TableID),
		foreign key (TestID) references Tests(TestID),
		foreign key (TableId) references [Tables](TableID)
)

drop table if exists TestRunViews
create table TestRunViews(
		TestRunID int not null,
		ViewID int not null,
		StartAt datetime not null,
		EndAt datetime not null,
		constraint PK_TestRunViews primary key(TestRunID, ViewID),
		foreign key (TestRunID) references TestRuns(TestRunID),
		foreign key (ViewID) references [Views](ViewID)
)

drop table if exists TestRunTables
create table TestRunTables(
		TestRunID int not null,
		TableID int not null,
		StartAt datetime not null,
		EndAt datetime not null
		constraint PK_TestRunTables primary key(TestRunID, TableID),
		foreign key (TestRunID)  references TestRuns(TestRunID),
		foreign key (TableID) references [Tables](TableID)
)

drop table if exists TestTables
create table TestTables(
		TestID int not null,
		TableID int not null,
		NoOfRows int not null,
		Position int not null,
		constraint PK_TestTables primary key(TestID, TableID),
		foreign key (TestID) references Tests(TestID),
		foreign key (TableID) references [Tables](TableID)
)

drop table if exists TestRunViews
create table TestRunViews(
		TestRunID int not null,
		ViewID int not null,
		StartAt datetime not null,
		EndAt datetime not null,
		constraint PK_TestRunViews primary key(TestRunID, ViewID),
		foreign key (TestRunID) references TestRuns(TestRunID),
		foreign key (ViewID) references [Views](ViewID)
)

drop table if exists TestRunTables
create table TestRunTables(
		TestRunID int not null,
		TableID int not null,
		StartAt datetime not null,
		EndAt datetime not null
		constraint PK_TestRunTables primary key(TestRunID, TableID),
		foreign key (TestRunID) references TestRuns(TestRunID),
		foreign key (TableID) references [Tables](TableID)
)

drop table if exists TestViews
create table TestViews(
		TestID int not null,
		ViewID int not null,
		constraint PK_TestViews primary key(TestID, ViewID),
		foreign key (TestID) references Tests(TestID),
		foreign key (ViewID) references [Views](ViewID)
)

drop table if exists [Tables]
create table [Tables](
		TableID int not null,
		TName varchar(50) not null,
		constraint PK_Tables primary key(TableID)
)

drop table if exists Tests
create table Tests(
		TestID int not null,
		TName varchar(50) not null,
		constraint PK_Tests primary key(TestID)
)

drop table if exists [Views]
create table [Views](
		ViewID int not null,
		VName varchar(50) not null
		constraint PK_Views primary key(ViewID)
)

drop table if exists TestRuns
create table TestRuns(
		TestRunID int not null,
		TDescription varchar(50) not null,
		StartAt datetime not null,
		EndAt datetime not null
		constraint PK_TestRuns primary key(TestRunID)
)



drop view if exists ViewPlayers
go
create view ViewPlayers
as
	select * from Players
go

drop view if exists ViewAchievements
go
create view ViewAchievements
as
	select * from Achievements
go

drop view if exists ViewPA
go
create view ViewPA
as
	select * from PA
go

delete from [Tables]
insert into [Tables] values(1, 'Achievements'), (2, 'Players'), (3, 'PA')

delete from [Views] 
insert into [Views] values (1, 'ViewPlayers'), (2, 'ViewAchievements'), (3, 'ViewPA')

delete from Tests
insert into Tests values (1, 'delete_table'), (2, 'insert_table'), (3, 'select_view')

delete from TestViews
insert into TestViews values (3, 1)

--select * from ViewEnchantments

delete from TestTables
insert into TestTables values (1, 2, 3, 2)
insert into TestTables values (2, 1, 5, 1)

go
create or alter proc insertPlayer
as
	declare @index int = 1
	declare @nrRows int
	select @nrRows = NoOfRows from TestTables where TestID = 2

	while @index < @nrRows
	begin
		insert into Players values (@index + 1, 'name' + CAST(@index as varchar(5)), 11111, 22222)
		set @index = @index + 1
	end
go

create or alter proc deletePlayer
as
	delete from Players where Pid > 1
go 

create or alter proc insertAchievement
as
	declare @index int = 1
	declare @nrRows int
	select @nrRows = NoOfRows from TestTables where TestID = 2

	while @index < @nrRows
	begin
		insert into Achievements values(@index + 1, 'name' + CAST(@index as varchar(5)), 'descr' + CAST(@index as varchar(5)))
		set @index = @index + 1
	end
go

create or alter proc deleteAchievement
as
	delete from Achievements where Aid > 1
go

create or alter proc insertPA
as
	declare @index int = 1
	declare @nrRows int
	select @nrRows = NoOfRows from TestTables where TestID = 2

	while @index < @nrRows
	begin
		insert into PA values(@index + 1, @index + 1)
		set @index = @index + 1
	end
go

create or alter proc deletePA
as
	delete from PA 
go

drop view if exists View4Tables 
go
create or alter view View4Tables
as
select I.Name, E.Weight, L.OriginalObject
from Items I inner join IE ie on I.Iid = ie.Iid
	inner join Enchantments E on E.Eid = ie.Eid
	inner join Loot L on L.Lid = I.Lid
go

--select * from View4Tables

alter table [Tables] with nocheck add
	constraint [PK_Tables] primary key clustered 
	(
		[TableID]
	)on [PRIMARY]
go

alter table TestRunTables with nocheck add
	constraint [PK_TestRunTables] primary key clustered
	(
		[TestRunID],
		[TableID]
	)on [PRIMARY]
go

alter table TestRunViews with nocheck add
	constraint [PK_TestRunViews] primary key clustered
	(
		[TestRunID],
		[ViewID]
	)on [PRIMARY]
go

alter table TestRuns with nocheck add
	constraint [PK_TestRuns] primary key clustered
	(
		[TestRunID]
	)on [PRIMARY]
go

alter table TestTables with nocheck add
	constraint [PK_TestTables] primary key clustered
	(
		[TestID],
		[TableID]
	)on [PRIMARY]
go

alter table TestViews with nocheck add
	constraint [PK_TestViews] primary key clustered
	(
		[TestID],
		[ViewID]
	)on [PRIMARY]
go

alter table TestRunViews with nocheck add
	constraint [PK_TestRunViews] primary key clustered
	(
		[TestRunID],
		[ViewID]
	)on [PRIMARY]
go

alter table Tests with nocheck add
	constraint [PK_Tests] primary key clustered
	(
		[TestID]
	)on [PRIMARY]
go

alter table [Views] with nocheck add
	constraint [PK_Views] primary key clustered
	(
		[ViewID]
	)on [PRIMARY]
go

alter table TestRunTables with nocheck add
	constraint [PK_TestRunTables] primary key clustered
	(
		TableID
	)references [Tables] (
		TableID	
	)on delete cascade on update cascade,
	constraint FK_TestRunTables_TestRuns foreign key 

	(

		[TestRunID]

	) references [TestRuns] (

		[TestRunID]

	) on delete cascade on update cascade
go