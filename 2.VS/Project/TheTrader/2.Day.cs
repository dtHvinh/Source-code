using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TheTrader
{
    internal class Day
    {
        const int max_goods = 3;
        private Goods[] today_goods;

        public Day()
        {
            this.today_goods = new Goods[ number.getRandom( max_goods )];
            // create get amount of good .

        }
    }
}
