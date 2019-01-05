using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            double x = double.Parse(textBox1.Text);
            double y = double.Parse(textBox2.Text);
            double z = double.Parse(textBox3.Text);

            double rezult = Math.Abs(Math.Pow(x, y / x) - Math.Pow(y / x, 0.3));
            rezult += (y - x) * (Math.Cos(y) - z / (y - x)) / (1 + (y - x) * (y - x));

            textBox4.Clear();
            textBox4.Text += "после вычислений вышло" + Environment.NewLine;
            textBox4.Text += Environment.NewLine + "\u03C8 = " + rezult.ToString();
        }
    }
}