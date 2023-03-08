using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TheTrader
{
    internal class number
    {
        public static int get()
        {
            return int.Parse(Console.ReadLine());
        }

        public static int getRandom(int to, int from = 1)
        {
            Random random = new Random();
            return random.Next(from, to+1);
        }
    }
}
