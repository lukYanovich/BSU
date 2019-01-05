using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab_4
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form1_1 f1 = new Form1_1();
            f1.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form1_2 f2 = new Form1_2();
            f2.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form1_3 f3 = new Form1_3();
            f3.ShowDialog();
        }
    }
}