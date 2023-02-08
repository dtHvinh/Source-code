using System;
namespace SwapIntProgram
{
    class Program
    {
        static void Swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        
        static void Main(string[] args)
        {
            int x = 10;
            int y = 20;

            Console.WriteLine("Before swapping: x = {0} and y = {1}", x, y);

            Swap(ref x, ref y);

            Console.WriteLine("After swapping: x = {0} and y = {1}", x, y);
        }


    }
}