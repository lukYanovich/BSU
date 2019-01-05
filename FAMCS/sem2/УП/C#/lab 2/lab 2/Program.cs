using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("задание 1.\n");
            double a, b;
            Console.Write("введите сумму вклада: ");
            a = double.Parse(Console.ReadLine());
            Console.Write("введите процент(годовых) по вкладу: ");
            b = double.Parse(Console.ReadLine());
            Console.Write("через год начислят ");
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("{0:#.##}p", a * b * 0.01);
            Console.ForegroundColor = ConsoleColor.Gray;


            Console.Write("\n\nзадание 2.\n\nплощадь полной поверхности куба равна: ");
            a = int.Parse(Console.ReadLine());
            Console.Write("ребро куба равно ");
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("{0:#.##}", Math.Sqrt((double)(a / 6)));
            Console.ForegroundColor = ConsoleColor.Gray;


            Console.Write("\n\nзадание 3.\n\nвведите число: ");
            a = int.Parse(Console.ReadLine());
            b = (int)0;
            while (a > 0)
            {
                b += (int)(a % 10);
                a /= (int)10;
            }
            Console.Write("сумма цифр: ", b);
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("{0}", b);
            Console.ForegroundColor = ConsoleColor.Gray;
            Console.Write(" - ");
            Console.ForegroundColor = ConsoleColor.Magenta;
            if (b % 10 == 0)
                Console.WriteLine("на конце 0.");
            else
                Console.WriteLine("на конце не 0.");
            Console.ForegroundColor = ConsoleColor.Gray;
        }
    }
}
