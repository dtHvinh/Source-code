using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaiCao
{
    internal class player
    {
        private static int idCounter = 0;
        public int id;
        public card[] player_hold = new card[3];
        private int pos = 0;
        public int score = 0;


        public void getCard(card _get_card)
        {
            this.player_hold[pos] = _get_card;
            this.score += this.player_hold[pos]._rankIndex >= 10 ? 1000 : this.player_hold[pos]._rankIndex+1;
            pos++;
        }

        public player()
        {
            this.id = idCounter++;
            Console.WriteLine("Player p" + (this.id+1) + " has joined.");
            Thread.Sleep(500);
            
        }

        public void info()
        {
            Console.WriteLine("This player p"+ this.id + " hold: " + this.pos + " cards");
            if(this.pos > 0)
            {
                for(int i = 0; i < this.pos; i++)
                {
                    player_hold[i].card_info();
                }
            }


            Console.WriteLine();
        }
    }
}
