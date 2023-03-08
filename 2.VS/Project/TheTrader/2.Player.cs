using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TheTrader
{
    internal class Player
    {
        private int current_money;

        public Player() { this.current_money = 0; }

        /// <summary>
        /// Add amount of money to %Player.
        /// </summary>
        /// <param name="value"> Amount of money to add.</param>
        public void earn(int value) { this.current_money = value; }

        public void info()
        {
            Console.WriteLine("Player Money: " + this.current_money);
        }

    }
}
