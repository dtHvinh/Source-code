using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace TheTrader
{
    internal class Player
    {
        private int current_money;
        private LinkedList<Goods> player_own;

        private Day current_Day;


        private void Buy(int index)
        {

        }

        private void Sell(int index)
        {

        } 

        /// <summary>
        /// Create a Player and its connection with Day %input. 
        /// </summary>
        /// <param name="input">Link Player to Day, and vice versa.</param>
        Player(Day input)
        {
            this.current_money = 0;
            this.current_Day = input;
        }

        public void Action()
        {
            Console.WriteLine("You will:");
            Console.WriteLine("[1]. Buy");
            Console.WriteLine("[2]. Sell");
            Console.WriteLine("[3]. Quit");
            int player_choice = int.Parse(Console.ReadLine());
            switch (player_choice)
            {
                case 1:
                    Console.WriteLine("Choose From  0 to " + current_Day.number_of_goods - 1 + ".");

            }
        }
        



        
    }
}
