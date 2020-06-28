use Lab3;
go
alter PROCEDURE AddAuthorBook
	@title varchar(100),
	@language varchar(100),
	@name varchar(100)
AS
BEGIN
	-- SET NOCOUNT ON added to prevent extra result sets from
	-- interfering with SELECT statements.
	SET NOCOUNT ON;

    -- Insert statements for procedure here
	declare @author int
	execute @author = AddAuthor @name
	if (@author <> 1)
	begin
		declare @book int
		execute @book = AddBook @title, @language
		if (@book <> 1)
			execute AddRelation
	end
END


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
EXEC AddAuthorBook 'Ritual cu ceapa','Palestiniana', 'iuliazzzz'
Select * from Books
Select * from Authors
Select * from BooksAuthors

Select * from Books
Select * from Authors
Select * from BooksAuthors
EXEC AddAuthorBook 'Game of thrones','English', 'diana45'
Select * from Books
Select * from Authors
Select * from BooksAuthors