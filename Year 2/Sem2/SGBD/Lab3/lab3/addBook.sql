use Lab3
GO
CREATE FUNCTION uf_ValidateLanguage (@language varchar(100)) RETURNS INT AS
BEGIN
DECLARE @return INT
SET @return = 0
IF(@language IN ('English','Romanian','French', 'Chinese'))
SET @return = 1
RETURN @return
END

GO

CREATE PROCEDURE AddBook @title varchar(50), @language varchar(50) AS
BEGIN
BEGIN TRAN
BEGIN TRY
IF(dbo.uf_ValidateLanguage(@language)<>1)
BEGIN
RAISERROR('Language must be Romanian, English, Chinese or French',14,1)
END
INSERT INTO Books (title, language) VALUES (@title, @language)
COMMIT TRAN
SELECT 'Transaction committed'
END TRY
BEGIN CATCH
ROLLBACK TRAN
SELECT 'Transaction rollbacked'
END CATCH
END


Select * from Books
EXEC AddBook 'Game of throgdfgdgfdnes','English'
Select * from Books

EXEC AddBook 'Ritual cu ceapa','Palestiniana'
Select * from Books

