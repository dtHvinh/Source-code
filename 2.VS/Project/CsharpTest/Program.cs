namespace CsharpTest
{ 
    internal class Program
    {
        static void Main(string[] args)
        {
            string s = "12:01:00AM";
            string sign = "";
            sign += s[8] + s[9];
            if (sign == "AM")
            {
                if (s[1] == '2')
                {
                    s[1] = '0';
                    s[0] = '0';
                }
            }
            else
            {   // PM
                if (s[1] == '2' && s[0] != 0)
                {
                    s[0] = '0';
                    s[0] = '0';
                }
                else
                {
                    int hour = (s[0] - '0') * 10 + s[1] - '0';
                    hour += 12;
                    s[0] = hour / 10;
                    s[1] = hour % 10;
                }
            }
            Console.WriteLine(time);
        }
    }
}