 using ASPLogin.Models;
using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Web;

namespace ASPLogin.DataAbstractionLayer
{
    public class DAL
    {

        public MySqlConnection GetConnection()
        {
            string connectionString = "server=localhost;uid=root;pwd=;database=users;";
            return new MySqlConnection(connectionString);
        }

        public bool login(string username, string password)
        {
            List<String> users = new List<String>();
            try 
            {
                MySqlConnection connection = GetConnection();
                connection.Open();

                MySqlCommand command = new MySqlCommand();
                command.Connection = connection;
                command.CommandText = "SELECT * FROM users WHERE Username = '" + username + "' AND Password = '" + password + "'";
                MySqlDataReader reader = command.ExecuteReader();

                while(reader.Read())
                {
                    users.Add(reader.GetString("username"));
                }
                reader.Close();
            }
            catch(MySqlException exception)
            {
                Console.Write(exception.Message);
                return false;
            }
            return users.Count == 1;

        }

        public List<Book> GetBooks()
        {
            MySqlConnection connection;
            string connectionString;

            connectionString = "server=localhost;uid=root;pwd=;database=books";
            List<Book> bookList = new List<Book>();

            try
            {
                connection = new MySqlConnection();
                connection.ConnectionString = connectionString;
                connection.Open();

                MySqlCommand cmd = new MySqlCommand();
                cmd.Connection = connection;
                cmd.CommandText = "SELECT * FROM Book";
                MySqlDataReader dataReader = cmd.ExecuteReader();

                while(dataReader.Read())
                {
                    Book book = new Book();
                    book.Author = dataReader.GetString("Author");
                    book.Genre = dataReader.GetString("Genre");
                    book.Lent = dataReader.GetInt32("Lent");
                    book.Pages = dataReader.GetInt32("Pages");
                    book.Title = dataReader.GetString("Title");
                    bookList.Add(book);
                }

            }
            catch (MySqlException ex)
            {
                Console.Write(ex.Message);
            }
            return bookList;
        }

        public void AddBook(string Author, string Title, int Pages, string Genre, int Lent)
        {
            MySqlConnection connection;
            string connectionString;

            connectionString = "server=localhost;uid=root;pwd=;database=books;";

            try
            {
                connection = new MySqlConnection();
                connection.ConnectionString = connectionString;
                connection.Open();

                MySqlCommand cmd = new MySqlCommand();
                cmd.Connection = connection;
                cmd.CommandText = "INSERT INTO Book (Author, Title, Pages, Genre, Lent) VALUES ('" + Author + "', '" + Title + "', " + Pages + ", '" + Genre + "', " + Lent + ")";
                cmd.ExecuteNonQuery();
            }
            catch(MySqlException ex)
            {
                Console.Write(ex.Message);
            }
        }

        public void DeleteBook(string Title)
        {
            MySqlConnection connection;
            string connectionString;

            connectionString = "server=localhost;uid=root;pwd=;database=books;";

            try
            {
                connection = new MySqlConnection();
                connection.ConnectionString = connectionString;
                connection.Open();

                MySqlCommand cmd = new MySqlCommand();
                cmd.Connection = connection;
                cmd.CommandText = "DELETE FROM Book WHERE Title = '" + Title + "'";
                cmd.ExecuteNonQuery();
            }
            catch (MySqlException ex)
            {
                Console.Write(ex.Message);
            }
        }

        public void UpdateBook(string Title, int Lent)
        {
            MySqlConnection connection;
            string connectionString;

            connectionString = "server=localhost;uid=root;pwd=;database=books;";

            try
            {
                connection = new MySqlConnection();
                connection.ConnectionString = connectionString;
                connection.Open();

                MySqlCommand cmd = new MySqlCommand();
                cmd.Connection = connection;
                cmd.CommandText = "UPDATE Book SET Lent = " + Lent + " WHERE Title = '" + Title +"' ";
                cmd.ExecuteNonQuery();
            }
            catch (MySqlException ex)
            {
                Console.Write(ex.Message);
            }
        }

        public Book GetBook(string Title)
        {
            MySqlConnection connection;
            string connectionString;

            connectionString = "server=localhost;uid=root;pwd=;database=books";
            Book book = new Book();

            try
            {
                connection = new MySqlConnection();
                connection.ConnectionString = connectionString;
                connection.Open();

                MySqlCommand cmd = new MySqlCommand();
                cmd.Connection = connection;
                cmd.CommandText = "SELECT * FROM Book WHERE Title = '" + Title + "' ";
                MySqlDataReader dataReader = cmd.ExecuteReader();

                while (dataReader.Read())
                {
                    book.Title = dataReader.GetString("Title");
                }
                dataReader.Close();
            }
            catch (MySqlException ex)
            {
                Console.Write(ex.Message);
            }

            return book;
        }

    }
}