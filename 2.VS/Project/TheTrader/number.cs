using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TheTrader
{
    internal class number
    {
        /// <summary>
        /// Generate a random number in range start to end.
        /// </summary>
        /// <param name="start"></param>
        /// <param name="end"></param>
        /// <returns></returns>
        public static int getRandom(int start, int end)
        {
            Random r = new Random();
            return r.Next(start, end);
        }

        /// <summary>
        /// Display a value.
        /// </summary>
        /// <param name="value"></param>
        public static void display(int value)
        {
            string formattedNumber = string.Format("{0:n0}", value).Replace(",", ".");
            Console.Write(formattedNumber);
            Console.WriteLine(".00$");
        }
    }
}
