BEGIN TRAN 
WAITFOR DELAY '00:00:10' 
INSERT INTO Books(title,language) VALUES ('At the end of the world','English') 
COMMIT TRAN