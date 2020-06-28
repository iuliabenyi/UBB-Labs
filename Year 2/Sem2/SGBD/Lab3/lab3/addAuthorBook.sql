use Lab3;
go
alter PROCEDURE AddAuthorBook
	@title varchar(100),
	@language varchar(100),
	@name varchar(100)
AS
begin
	SET NOCOUNT ON;
    begin tran
		begin try
			if (dbo.uf_ValidateLanguage(@language) <> 1)
			begin
				INSERT INTO Authors(name) VALUES (@name)
				print 'Insert author complete'
				--commit tran
				RAISERROR('Language not good', 14, 1)
			end

			if (dbo.uf_ValidateName(@name) <> 1)
			begin
				INSERT INTO Books (title, language) VALUES (@title, @language)
				print 'Insert book complete'
				--commit tran
				RAISERROR('Name not good', 14, 1)				
			end

			INSERT INTO Books (title, language) VALUES (@title, @language)
			print 'Insert book complete'

			INSERT INTO Authors(name) VALUES (@name)
			print 'Insert author complete'
			
			declare @bid int
			set @bid = (select IDENT_CURRENT('Books'))
			declare @aid int
			set @aid = (select IDENT_CURRENT('Authors'))
			insert into BooksAuthors(author_id, book_id) values(@aid, @bid)
			print 'Insert relationship complete'
			commit tran
			select 'Transaction committed'
		end try

		begin catch
			select 'Transaction rollbacked'
			print ERROR_MESSAGE()
			rollback tran
		end catch
	end



Select * from Books
Select * from Authors
Select * from BooksAuthors
EXEC AddAuthorBook 'popo', 'English', 'diana'
Select * from Books
Select * from Authors
Select * from BooksAuthors

Select * from Books
Select * from Authors
Select * from BooksAuthors
EXEC AddAuthorBook 'Ritual cu ceapa','Palestiniana', 'iulia'
Select * from Books
Select * from Authors
Select * from BooksAuthors

Select * from Books
Select * from Authors
Select * from BooksAuthors
EXEC AddBookAuthor 'Game of thrones','English', 'diana'
Select * from Books
Select * from Authors
Select * from BooksAuthors