USE Minecraft
GO 

INSERT INTO Biomes VALUES(11,'Plains')
INSERT INTO Biomes VALUES(12,'Savannah')
INSERT INTO Biomes VALUES(13,'Forest')
INSERT INTO Biomes VALUES(14,'Jungle')
INSERT INTO Biomes VALUES(15,'')
--INSERT INTO Biomes VALUES(5,'AAA')

--INSERT INTO Items VALUES(100,null,null,null,null,14,null,null)

INSERT INTO Players VALUES(100, 'username1',1000,1001)
INSERT INTO Players VALUES(200, 'username2',2000,2002)
INSERT INTO Players VALUES(300, 'username3',3000,3003)
INSERT INTO Players VALUES(400, 'username4',4000,4004)
INSERT INTO Players VALUES(500, 'username5',5000,5005)

UPDATE Players
SET Username = 'UpdateUsername'
WHERE Pid = 100 OR Username = 'username2'

DELETE FROM Players
WHERE Pid>=100 AND Pid<=500

DELETE FROM Biomes
WHERE Bid >=11 

INSERT INTO Enchantments VALUES(100,'name1',100,100)
INSERT INTO Enchantments VALUES(101,'name2',101,101)
INSERT INTO Enchantments VALUES(102,'name3',102,102)
INSERT INTO Enchantments VALUES(103,'name4',103,103)
INSERT INTO Enchantments VALUES(104,'name5',104,104)

DELETE FROM Enchantments
WHERE Eid BETWEEN 100 AND 104

DELETE FROM Items
WHERE Pid IS NULL


UPDATE Players
SET CoordinatesX = 111
WHERE CoordinatesX = 100

UPDATE Players
SET CoordinatesX = 999, CoordinatesY = 888, Username = 'Updated1'
WHERE Pid = 3

INSERT INTO Enchantments VALUES(100, 'testName1',1,1)
INSERT INTO Enchantments VALUES(101, 'testName2',2,2)
INSERT INTO Enchantments VALUES(102, 'testName3',3,3)

UPDATE Enchantments
Set MaximumLevel = 9999
Where Name LIKE 'test%'

INSERT INTO Enchantments VALUES(200, 'testName4',4,4)
INSERT INTO Enchantments VALUES(201, 'testName5',5,5)
INSERT INTO Enchantments VALUES(202, 'testName6',6,6)

UPDATE Enchantments
Set MaximumLevel = 8888
Where Name IN ('testName4', 'testName5', 'testName6')

--a. 2 queries with the union operation; use UNION [ALL] and OR;
-- displays the names of the Enchantments and the Biomes
SELECT DISTINCT Name FROM Enchantments
UNION ALL
SELECT Name FROM Biomes

-- displays the name of the Enchantments that have the maximum level 3 or their ID is greater than 200
SELECT Name FROM Enchantments
WHERE MaximumLevel = 3 OR Eid>200

-- b. 2 queries with the intersection operation; use INTERSECT and IN;
-- displays the Items and the Enchantments that have the same ID
SELECT Eid FROM Enchantments
INTERSECT
SELECT Iid FROM Items

-- displays the distinct ID and name of the players that have the ID 1, 2, 3, 4 or 5
SELECT DISTINCT Pid, Username FROM Players
WHERE Pid IN (1, 2, 3, 5) OR Pid IN (4)

--c. 2 queries with the difference operation; use EXCEPT and NOT IN;
-- displays the items that don't have a loot
SELECT Loot.Lid FROM Loot
EXCEPT
SELECT Items.Lid FROM Items

-- displays the Original object from a Loot whose id is not 1, 2, 3, 4, 5, 6, 7, 8 or 9
SELECT OriginalObject FROM Loot
WHERE Lid NOT IN (1,2,3,4,5,6,7,8,9)

--d. 4 queries with INNER JOIN, LEFT JOIN, RIGHT JOIN, and FULL JOIN; 
--one query will join at least 3 tables, while another one will join at least two many-to-many relationships;
-- displays the players that have achievements
SELECT Players.Username, Achievements.Name
FROM Players
INNER JOIN PA
ON Players.Pid=PA.Pid
INNER JOIN Achievements
ON Achievements.Aid=PA.Aid -- one many to many

-- displays the name of the mobs and the biomes in which they are found 
SELECT Mobs.Name, Biomes.Name
FROM Mobs
LEFT JOIN BM
ON Mobs.Mid=BM.Mid 
LEFT JOIN Biomes
ON Biomes.Bid=BM.Bid --3 tables

-- displays the name of the biomes and their structures 
SELECT Biomes.Name, Structures.Name
FROM Biomes
RIGHT JOIN Structures
ON Biomes.Bid=Structures.Bid

-- displays the names of the items, enchantments, biomes and mobs
SELECT Items.Name, Enchantments.Name, Biomes.Name, Mobs.Name
FROM Items 
FULL JOIN IE
ON Items.Iid=IE.Iid
FULL JOIN Enchantments
ON Enchantments.Eid=IE.Eid
FULL JOIN Biomes
ON Biomes.Bid=Items.Bid
FULL JOIN BM
ON Biomes.Bid=BM.Bid
FULL JOIN Mobs
ON Mobs.Mid=BM.Mid  -- 2 many-to-many relationships

-- displays the name of the enchanted items of mobs from biomes
SELECT Items.Name, Enchantments.Name, Biomes.Name, Mobs.Name
FROM Items 
INNER JOIN IE
ON Items.Iid=IE.Iid
INNER JOIN Enchantments
ON Enchantments.Eid=IE.Eid
INNER JOIN Biomes
ON Biomes.Bid=Items.Bid
INNER JOIN BM
ON Biomes.Bid=BM.Bid
INNER JOIN Mobs
ON Mobs.Mid=BM.Mid



--e. 2 queries using the IN operator to introduce a subquery in the WHERE clause; 
--in at least one query, the subquery should include a subquery in its own WHERE clause;
-- displays the items from trading
SELECT DISTINCT Items.Name
FROM Items
WHERE Items.Tid IN (SELECT Trading.Tid FROM Trading)

-- displays the items found in the structures from different biomes
SELECT Items.Name
FROM Items
WHERE Items.Bid IN (SELECT Biomes.Bid FROM Biomes WHERE Biomes.Bid IN (SELECT Structures.Bid FROM Structures))

--f. 2 queries using the EXISTS operator to introduce a subquery in the WHERE clause;
-- displays the items if there are IDs greater than 80 or lower than 0
SELECT Items.Name
FROM Items
WHERE EXISTS(SELECT Items.Iid FROM Items WHERE (Items.Iid >= 80 AND Items.Iid <= 0))

--displays the items if there is an item named "Pickaxe"
SELECT Items.Name
FROM Items
WHERE EXISTS(SELECT Items.Name FROM Items WHERE Items.Name = 'Pickaxe')


--g. 2 queries with a subquery in the FROM clause;   
-- displays the achievements' names
SELECT Name
FROM (SELECT Name FROM Achievements) AS AchName 

-- displays the items' names
SELECT Name
FROM (SELECT Name FROM Items) AS ItemName


--h. 4 queries with the GROUP BY clause, 3 of which also contain the HAVING clause; 
--2 of the latter will also have a subquery in the HAVING clause; 
--use the aggregation operators: COUNT, SUM, AVG, MIN, MAX;
-- displays the top 3 items whose minimum id is lower than the average of all the IDs
SELECT TOP 3 MAX(Items.Name)
FROM Items
GROUP BY Items.Type
HAVING MIN(Items.Iid) < ALL(SELECT AVG(Items.Iid) FROM Items)

--displays the items whose id sum is greater than 1
SELECT MAX(Items.Name)
FROM Items
GROUP BY Items.Iid
HAVING SUM(Items.Iid) > 1

--displays the items that are found in a certain biom
SELECT MAX(Items.Name)
FROM Items
GROUP BY  Items.Iid
HAVING Items.Iid IN (SELECT Items.Bid FROM Items)

--displays the lowest 5 items by name
SELECT TOP 5 MIN(Items.Name)
FROM Items
GROUP BY Items.Name

--i. 4 queries using ANY and ALL to introduce a subquery in the WHERE clause; 
--2 of them should be rewritten with aggregation operators, while the other 2 should also be expressed with [NOT] IN.
-- displays the items that have the durability greater than any item's ID
SELECT Items.Name
FROM Items
WHERE Items.Durability > ANY(SELECT Items.Iid FROM Items)
ORDER BY Items.Durability

-- displays the items that have the durability greater than the minimum ID
SELECT Items.Name
FROM Items
WHERE Items.Durability > ANY(SELECT MIN(Items.Iid) FROM Items) --rewritten with aggregation op

--
SELECT Items.Name
FROM Items
WHERE Items.Durability > ANY(SELECT items.Iid FROM Items)
ORDER BY Items.Durability

--displays the items whose durability is not equal to any item ID
SELECT Items.Name
FROM Items
WHERE Items.Durability NOT IN (SELECT items.Iid FROM Items)
ORDER BY Items.Durability --rewritten with NOT IN

-- displays the traders that have the ID greater than any item ID
SELECT Trading.Trader
FROM Trading
WHERE Trading.Tid >= ANY(SELECT Trading.Iid FROM Trading)

SELECT Trading.Trader
FROM Trading
WHERE Trading.Tid IN (SELECT Trading.Iid FROM Trading) --rewritten with IN

--displays the items that have the durability higher than any item ID
SELECT Items.Name
FROM Items
WHERE Items.Durability < ANY(SELECT Items.Iid FROM Items)
ORDER BY Items.Durability

SELECT Items.Name
FROM Items
WHERE Items.Durability < ANY(SELECT MAX(Items.Iid) FROM Items) --rewritten with aggregation op
