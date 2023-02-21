using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaiCao
{
    internal class card
    {
        private string suit;
        private string rank;
        private string state;
        public  int    _rankIndex;
        // 0->3  == 4
        private string[] suits  = { "Heart", "Diamond", "Spade", "Club"};
        // 0->12 == 13
        private string[] ranks  = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen" , "King"};
        // 0->1 
        private string[] states = { "face down", "face up" };
        public card(int _suitIndex, int _rankIndex) 
        {
            this.suit  = suits[_suitIndex];
            this.rank  = ranks[_rankIndex];
            this._rankIndex= _rankIndex;
            this.state = states[0];
        }

        public void card_info()
        {
            if(this.state == states[0])
            {
                Console.WriteLine(this.suit);
            }
            else
            {
                Console.WriteLine(this.rank + " of " + this.suit);
            }
        }
       
        public void flip()
        {
            this.state = (this.state == states[1]) ? states[0] : states[1];
        }


    }
}
