using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TheTrader
{
    internal class Goods_name
    {
        private static string[] name = { "plane", "house", "car", "apple", "banana", "TV", "Sofa" };

        public static string getRandom()
        {
            return name[number.getRandom(0, name.Length)];
        }

    }
}
