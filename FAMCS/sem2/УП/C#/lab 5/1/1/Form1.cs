using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1
{
    public partial class MainForm : Form
    {
        public int x = 0, y = 0;
        public bool flag = true; //true - увеличить, false - уменьшить

        public MainForm()
        {
            InitializeComponent();
        }

        private void menuToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (x != 0 || y != 0)
                changeToolStripMenuItem.Enabled = true;
            this.menuToolStripMenuItem.Click += new System.EventHandler(this.menuToolStripMenuItem_Click);
        }

        private void inputSizeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _Form1 frm = new _Form1();
            frm.ShowDialog(this);
        }

        private void chooseToolStripMenuItem_Click(object sender, EventArgs e)
        {
            _Form2 frm = new _Form2();
            frm.ShowDialog(this);
        }

        private void changeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Size size;
            if (flag==true)
                size = new Size(this.Width + x, this.Height + y);
            else
                size = new Size(this.Width - x, this.Height - y);
            this.Size = size;
            this.Refresh();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}