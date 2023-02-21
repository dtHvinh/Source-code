using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaiCao
{
    internal class loading
    {
        private static int cooldown = 50;

        public static void DeckCreate()
        {
            Console.WriteLine();
            Console.WriteLine("Deck has been created.");
            Thread.Sleep(2000);
            Console.Clear();
        }
        public static void shuffing_printScreen(){
            Console.Write("Shuffing.");
            for (int i = 0; i <=  5; i++)
            {
                Console.Write(".");
                Thread.Sleep(cooldown);
                cooldown += 50;
            }
            Console.Clear();
            Console.WriteLine("Shuffing Done.");
            Thread.Sleep(500);
        }
    }
}
