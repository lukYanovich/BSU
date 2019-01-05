using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace railwaySwation.Entity
{
    public class TrainFull
    {
        public long Id { get; set; }
        public string startTown { get; set; }
        public System.DateTime startDate { get; set; }
        public System.TimeSpan startTime { get; set; }
        public string finishTown { get; set; }
        public System.DateTime finishDate { get; set; }
        public System.TimeSpan finishTime { get; set; }
        public int price { get; set; }
        public int countOfTickets { get; set; }

        public static IEnumerable<TrainFull> getTrains()
        {
            var arr = new List<TrainFull>();
            try
            {
                Models.TrainDBEntities1 db = new Models.TrainDBEntities1();
                foreach (var train in db.Trains)
                {
                    var place = db.Places.FirstOrDefault(x => x.IdOfTrain == train.Id);
                    if (place.countOfEmptyPlaces == 0)
                        continue;

                    var item = new TrainFull();
                    
                    item.countOfTickets = place.countOfEmptyPlaces;
                    item.Id = train.Id;
                    item.startTown = train.startTown;
                    item.startDate = train.startDate;
                    item.startTime = train.startTime;
                    item.finishTown = train.finishTown;
                    item.finishDate = train.finishDate;
                    item.finishTime = train.finishTime;
                    item.price = train.price;                   
                    
                    arr.Add(item);
                }
            }
            catch (Exception ex)
            {
                //TODO: do something
            }
            return arr;
        }
    }
}