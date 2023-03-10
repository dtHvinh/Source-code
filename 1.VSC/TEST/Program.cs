internal class Program
{
    static void Main(string[] args)
    {
        Random com = new Random(2);
        int t  = com.Next(2);
        
        string[] computer = {"keo", "bua", "bao" };
        Console.WriteLine(computer[t]);
    }
}
