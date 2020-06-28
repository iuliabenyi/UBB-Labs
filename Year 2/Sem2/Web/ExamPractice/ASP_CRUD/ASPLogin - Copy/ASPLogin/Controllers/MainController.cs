using ASPLogin.DataAbstractionLayer;
using ASPLogin.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace ASPLogin.Controllers
{
    public class MainController : Controller
    {
        // GET: Main
        public ActionResult Index()
        {
            return View("Main");
        }

        public ActionResult ViewGetBooks()
        {
            DAL dal = new DAL();
            List<Websites> webs = dal.GetWebsites();
            ViewData["webList"] = webs;
            return View("ViewGetBooks");
        }

        public ActionResult ViewAddBook()
        {
            return View("ViewAddBook");
        }

        public ActionResult ViewDeleteBook()
        {
            return View("ViewDeleteBook");
        }

        public ActionResult ViewUpdateBook()
        {
            return View("ViewUpdateBook");
        }

        
    }
}