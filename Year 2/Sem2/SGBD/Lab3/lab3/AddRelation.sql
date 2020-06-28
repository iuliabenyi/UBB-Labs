USE Lab3
GO

Alter PROCEDURE AddRelation
AS
BEGIN
	SET NOCOUNT ON;

    begin tran
		begin try
			declare @bid int
			set @bid = (select IDENT_CURRENT('Books'))
			declare @aid int
			set @aid = (select IDENT_CURRENT('Authors'))
			insert into BooksAuthors values(@bid, @aid)
			print 'Insert relation complet'
			commit tran
			select 'Transaction committed'
		end try

		begin catch
			rollback tran
			select 'Relation transaction rollbacked'
		end catch
	end