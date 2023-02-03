using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Process 
    {
        string player , com;
        public Process(string player , string com) {
            this.player = player;
            this.com = com;
        }

        public void WaitingScreen()
        {
            int wait = 1247;
            Console.Clear();
            for (int i = 1; i <= 120; i++) 
            {
                Console.Write("*");
                if(i % 6 == 0)
                {
                    Thread.Sleep(wait);
                    if(wait -200 > 0 ) wait -= 200;
                }
            }
            Console.Clear();
        }
        public string calculate()
        {
            if(player == "keo")
            {
                if (com == "keo") return "Hoa";
                if (com == "bua") return "Thua";
                if (com == "bao") return "Thang";
            }
            else if(player == "bua")
            {
                if (com == "keo") return "Thang";
                if (com == "bua") return "Hoa";
                if (com == "bao") return "Thua";
            }
            else
            {
                if (com == "keo") return "Thua";
                if (com == "bua") return "Thang";
                if (com == "bao") return "Hoa";
            }
            return "Error";
        }

    }
}
