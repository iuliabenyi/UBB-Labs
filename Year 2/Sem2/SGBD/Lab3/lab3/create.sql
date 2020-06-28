create database Lab3
go
use Lab3
go
CREATE TABLE Books(
id INT PRIMARY KEY IDENTITY,
title varchar(100),
language varchar(100))
CREATE TABLE Authors(
id INT PRIMARY KEY IDENTITY,
name varchar(100))
CREATE TABLE BooksAuthors(
author_id INT FOREIGN KEY REFERENCES Authors(id),
book_id INT FOREIGN KEY REFERENCES Books(id),
CONSTRAINT pk_BooksAuthors PRIMARY KEY (author_id, book_id))


insert into Books values
('A court of Thorns and Roses', 'english'),
('Eleanour and Park', 'english'),
('City of Bones', 'english')
select * from Books