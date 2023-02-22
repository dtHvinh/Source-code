using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test
{
    internal class number
    {
        public static int getInt()
        {
            return int.Parse(Console.ReadLine());
        }
        public static int getRandom()
        {
            Random n = new Random();
            return n.Next();
        }
        public static int getRandomInRange(int start, int end)
        {
            Random n = new Random();
            return n.Next(start,end+1);
        }
    }
}
