using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Xml.XPath;

namespace AnotherGame
{
    internal class mainProcessor 
    {
        static void Main(string[] args)
        {
            paintingField a = new paintingField(5);
            a.DisplayField();
        }
    }
}
