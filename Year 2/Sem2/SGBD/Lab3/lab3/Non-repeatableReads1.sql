INSERT INTO Books(title, language) VALUES ('Peter Pan','Romanian') 
BEGIN TRAN 
WAITFOR DELAY '00:00:10' 
UPDATE Books SET language='English' WHERE title = 'Peter Pan' 
COMMIT TRAN