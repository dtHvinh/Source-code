using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace TheTrader
{
    internal class Goods
    {
        private string[] name = { "apple", "banana", "TV", "sofa", "House", "Car", "Plane" };

        private String Goods_name;
        
        private int Goods_values;

        public void getRandomGoods()
        {
            this.Goods_name = name[ number.getRandom(0, this.name.Length) ]; 
            
            // implement a func. to get value of goods;
        }
        
    }
}
