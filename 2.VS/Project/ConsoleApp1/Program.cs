namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            while(true)
            {
                //  Menu nguoi choi lua chon
                Console.WriteLine("Keo   = 1");
                Console.WriteLine("Bua   = 2");
                Console.WriteLine("Bao   = 3");
                Console.WriteLine("Thoat = 0");
                Console.Write("BAN CHON: ");

                //  input
                int a = int.Parse(Console.ReadLine());

                //  Thong bao lua chon nguoi choi
                Console.WriteLine();
                string[] player = { "Ban Da Thoat", "keo", "bua", "bao" };
                Console.WriteLine( (a == 0 || a >= 4 ) ? player[0] : "Ban da chon: " + player[a]);
                
                //  Dung game
                if (a == 0 || a >= 4) break;

                //  May Chon
                Random com = new Random();
                int t  = com.Next(3);
                
                string[] computer = {"keo", "bua", "bao" };
                Console.WriteLine("May chon:    "+ computer[t]);

                // Thoi gian Xem Lua chon cua Com va Player
                Thread.Sleep(1000);

                // Tinh toan
                Process pro = new Process(player[a], computer[t]);
                string result = pro.calculate();

                // Mang hinh cho cac thu cho no co mau sac voi nguoi ta thoi chu ko co chuc nang gi ca
                pro.WaitingScreen();

                // In ra ket qua
                System.Console.WriteLine(result);
                System.Threading.Thread.Sleep(2000);
                System.Console.Clear();
            } 
        }
    }
}