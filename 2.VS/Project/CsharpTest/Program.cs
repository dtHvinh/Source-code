namespace CsharpTest
{
    class display{
        public static void hello()
        {
            Console.WriteLine("Hello");
        }
        public void hello2() 
        {
            Console.WriteLine("Hello2");
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            display a = new display();
            a.hello2();
        }
    }
}