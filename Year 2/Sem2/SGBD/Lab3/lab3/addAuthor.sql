use Lab3
GO

Drop Function dbo.uf_ValidateName
CREATE FUNCTION uf_ValidateName (@name varchar(100)) RETURNS INT AS
BEGIN
DECLARE @return INT
SET @return = 0
IF(@name != 'abc')
SET @return = 1
RETURN @return
END

GO

DROP PROCEDURE dbo.AddAuthor;  
GO  

CREATE PROCEDURE AddAuthor @name varchar(50) AS
BEGIN
BEGIN TRAN
BEGIN TRY
IF(dbo.uf_ValidateName(@name)<>1)
BEGIN
RAISERROR('Name cannot be null',14,1)
END
INSERT INTO Authors(name) VALUES (@name)
COMMIT TRAN
SELECT 'Transaction committed'
END TRY
BEGIN CATCH
ROLLBACK TRAN
SELECT 'Transaction rollbacked'
END CATCH
END


Select * from Authors
EXEC AddAuthor 'Gicu'
Select * from Authors

EXEC AddAuthor 'abc'
Select * from Authors

