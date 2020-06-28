using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ASPLogin.Models
{
    public class Book
    {
        public string Author { get; set; }
        public string Genre { get; set; }
        public int Lent { get; set; }
        public int Pages { get; set; }
        public string Title { get; set; }
    }
}