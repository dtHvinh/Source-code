using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TheTrader
{
    internal class Goods
    {
        private string name;
        private int value;

        /// <summary>
        /// Get ramdom goods whenever the Goods object was create.
        /// </summary>
        public Goods() {
            this.name = Goods_name.getRandom();
            this.value = Goods_value.value( this.name );
        }


        /// <summary>
        /// Display Goods`s name and Goods`s value.
        /// </summary>
        public void info()
        {
            Console.Write(this.name.ToUpper() + ": "); number.display(this.value);
        }
    }
}
