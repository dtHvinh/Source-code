using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaiCao
{
    internal class propdeck
    {
// deck properties

        card[] deck_of_card = new card[52];
        private int top_Index = 0;
        private player[] players = new player[18];

// end properties

// assign Deck`s properties value
        private void swap(ref card c1, ref card c2)
        {
            card temp = c1;
            c1 = c2;
            c2 = temp;
        }
        /// <summary>
        /// Generate a whole deck of cards.
        /// </summary>
        public propdeck()
        {
            // Announced that deck was created
            loading.DeckCreate();
            // and wait 1s before on going.
            for (int i = 0; i <=3 ; i++)
            {
                for(int j = 0; j <= 12; j++)
                {
                    this.deck_of_card[top_Index++] = new card(i, j);
                }
            }
            this.top_Index -= 1;
        }
        public void players_register(player[] players)
        {
            this.players = players;
        }

//- assign Deck`s properties value

// deck display

        /// <summary>
        /// Display all of the current cards in the deck
        /// </summary>
        public void deck_info()
        {
            Console.WriteLine("Decks now have: " + this.players.Length + " players");
        }

//end deck display

//card manipulation

        /// <summary>
        /// Flip all current cards in the deck
        /// </summary>
        public void flip_all_deck()
        {
            for (int i = 0; i <= top_Index; i++)
            {
                this.deck_of_card[i].flip();
            }
        }
        /// <summary>
        /// get Top card of the Deck
        /// </summary>
        /// <returns>The card of the top of the deck.</returns>
        public card take_top_card()
        {
            card res = this.deck_of_card[top_Index];
            this.top_Index--;
            return res;
        }

        /// <summary>
        /// Shuffle all cards 50 times
        /// </summary>
        public void shuffle()
        {
            // Announced that deck has been shuffle
            loading.shuffing_printScreen();
            //
            Random number = new Random();
            int loop = 52;
            while(loop-- > 0)
            {
                int pos1 = number.Next(0, 52);
                int pos2 = number.Next(0, 52);
                swap(ref deck_of_card[pos1],ref deck_of_card[pos2]);
            }
        }

        /// <summary>
        /// Deal card to all players
        /// </summary>
        public void deal_cards_to_All_players()
        {
            Console.WriteLine("Dealing...");
            Thread.Sleep(1450);
            Console.Clear();

            for(int i = 0; i < this.players.Length; i++)
            {
                int times = 3;
                while(times-- > 0)
                {
                    players[i].getCard(take_top_card());
                }
            }
            Console.WriteLine("Deal done.");
        }

        private void open_all_card()
        {
            for (int i = 0; i < players.Length; i++)
            {
                for(int j = 0; j <= 2; j++)
                {
                    players[i].player_hold[j].flip();
                }
                players[i].info();
            }
            for (int i = 0; i < players.Length; i++)
            {
                Console.WriteLine("Player p" + players[i].id + " Score: " + players[i].score % 10);
            }
        }

        public void result()
        {
            int max = -1;
            int winner = 0;
            for(int i = 0; i < players.Length; i++)
            {
                if (players[i].score >= 3000)
                {
                    winner = i;
                    break;
                }
                if (players[i].score > max)
                {
                    max = players[i].score;
                    winner = i;
                }
            }
            Console.WriteLine("Winner is: Player p" + players[winner].id);
        }

//end card manipulation

// Menu
        public void menu()
        {
            while(true)
            {
                Console.WriteLine("1. Open All Cards");
                Console.WriteLine("2. Result");
                Console.WriteLine("3. Quit");
                Console.WriteLine();
                Console.Write("Your choice: ");
                int choice = int.Parse(Console.ReadLine());
                Console.Clear();
                switch (choice)
                {
                    case 1:
                        {
                            open_all_card();
                            break;
                        }
                    case 2:
                        {
                            result();
                            Thread.Sleep(1000);
                            return;
                        }
                    case 3:
                        {
                            return;
                        }
                }
            }
        }
    }
}
