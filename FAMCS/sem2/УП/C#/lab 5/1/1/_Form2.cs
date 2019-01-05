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
    public partial class _Form2 : Form
    {
        public _Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MainForm frm = (MainForm)Owner;
            if (radioButton1.Checked)
                frm.flag = true;
            else
                frm.flag = false;
            this.Close();
        }
    }
}
