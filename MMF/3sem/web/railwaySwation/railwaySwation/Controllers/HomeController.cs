using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace railwaySwation.Controllers
{
    public class HomeController : Controller
    {
        // GET: Home

        private Models.TrainDBEntities1 db = new Models.TrainDBEntities1();

        public ActionResult Index()
        {
            var Items = db.Trains;
            return View(Items);
        }

        public ActionResult TrainPage()
        {
            var items = Entity.TrainFull.getTrains();
            return View(items);
        }

        public ActionResult GetTrainsBlock()
        {
            var trains = db.Trains;
            return PartialView("~/Views/Home/TrainsBlock.cshtml", trains);
        }

        public ActionResult OrderTicketPage(int id = 0)
        {
            if(id == 0)
            {
                return RedirectToAction("TrainPage");
            }

            //var currentTrain = db.Trains.FirstOrDefault(x => x.Id == id);

            return View();
        }
    }
}