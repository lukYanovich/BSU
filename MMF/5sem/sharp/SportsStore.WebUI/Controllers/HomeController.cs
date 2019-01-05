using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;

namespace SportsStore.WebUI.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult About()
        {
            var cookie = new HttpCookie("cookies");
            cookie.Value = DateTime.Now.ToString("T");
            Response.SetCookie(cookie);
            return View();
        }

    }
}
