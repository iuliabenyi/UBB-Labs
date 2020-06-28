using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Linq;
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

    }
}