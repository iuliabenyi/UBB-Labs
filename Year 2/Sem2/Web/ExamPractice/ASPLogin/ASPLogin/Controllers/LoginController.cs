using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using ASPLogin.DataAbstractionLayer;

namespace ASPLogin.Controllers
{
    public class LoginController : Controller
    {
        // GET: Login
        public ActionResult Index()
        {
            return View("Login");
        }

        public ActionResult Login()
        {
            string username = Request.Params["username"];
            string password = Request.Params["password"];

            DAL dal = new DAL();
            bool result = dal.login(username, password);

            return Json(new { success = result });
        }
    }
}