using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CsharpTest
{
    internal class Math
    {
        string time;

        public string hold {
            get { return time; }
            set { time = hold; }
        }

        public string timeConversion(ref string s)
        {
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
                    s[0] = hour / 10 + '0';
                    s[1] = hour % 10 + '0';
                }
            }
            return s.Substring(0, s.Length - 2);
        }

    }
