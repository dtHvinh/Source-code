namespace BaiCao
{
    internal class main
    {
        static void Main(string[] args)
        {

            // assign numbers of players.
            int n;
            System.Console.WriteLine("How many player: ");
            while (true)
            {
                n = int.Parse(Console.ReadLine());
                if(n <= 17) { break; }
                else
                {
                    Console.WriteLine("Invalid numbers of player!");
                    Console.WriteLine("Please Re-enter numbers of players: ");
                }
            }
            //-assign

            // Player
            player[] players = new player[n];

            while (n-- >= 1)
            {
                players[n] = new player();
            }
            //-player

            // Deck
            propdeck deck_of_card = new propdeck();
            deck_of_card.players_register(players);
            deck_of_card.shuffle();
            //-Deck


            //// Deal cards                                                              //Error
            deck_of_card.deal_cards_to_All_players();
            ////-Deal cards

            // Menu
            deck_of_card.menu();


        }
    }
}