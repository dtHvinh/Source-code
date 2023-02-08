using System.Drawing;

namespace AnotherGame
{
    internal class paintingField
    {
        int size;
        int[,] field;

        // initial size value and create square field.
        public paintingField(int size) 
        {
            this.size = size;
            field = new int[size,size];
            FillWithOne();
        }

        // Fill the field with full number 1;
        public void FillWithOne()
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    field[i, j] = 1;
                }
            }
        }

        // Display and painting field;
        public void DisplayField()
        {
            for(int i = 0; i < size; i++)
            {
                for(int j = 0; j < size; j++)
                {
                    Console.WriteLine(field[i, j]);
                }
                Console.WriteLine();
            }
        }




    }
}