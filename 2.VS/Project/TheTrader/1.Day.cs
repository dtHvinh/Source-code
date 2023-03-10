using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TheTrader
{
    internal class Day
    {
        public static int Day_No = 1;
        public int number_of_goods;

        public LinkedList<Goods> today_goods = new LinkedList<Goods>();

        /// <summary>
        /// Initialize toDay Goods.
        /// </summary>
        public Day()
        {
            this.number_of_goods = number.getRandom(1, 6); // [1, 5]


            for(int i = 0; i < number_of_goods; i++)
            {
                today_goods.AddLast(new Goods());
            }
        }

        public void info()
        {
            int i = 0;
            Console.WriteLine("Day " + Day_No++);
            if(today_goods.Count > 0)
                foreach(Goods item in today_goods)
                {
                    Console.Write("[" + i++ +"] ");
                    item.info();
                }
            else{ Console.WriteLine("Empty!"); }
        }
    }
}
