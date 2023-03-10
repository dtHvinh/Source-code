using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TheTrader
{
    internal class Goods_value : Goods_name
    {
        public static int value(String name)
        {
            switch (name.ToLower())
            {
                case "plane":
                    return number.getRandom(300000000, 1500000000); // $300M to $1.5B
                case "house":
                    return number.getRandom(45000, 1700000); // $450k to $1.7M
                case "car":
                    return number.getRandom(10000, 50000); // $10K to $50K
                case "apple":
                    return number.getRandom(5, 10); // $100 to $500
                case "banana":
                    return number.getRandom(5, 7); // $50 to $200
                case "tv":
                    return number.getRandom(1000, 5000); // $1K to $5K
                case "sofa":
                    return number.getRandom(1000, 2000); // $1K to $2K
                default:
                    throw new ArgumentException($"Unknown item: {name}");
            }
        }
    }
}
