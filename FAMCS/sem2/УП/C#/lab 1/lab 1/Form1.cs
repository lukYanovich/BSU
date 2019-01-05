using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab_1
{
    public partial class myForm : Form
    {
        public myForm()
        {
            InitializeComponent();
            this.MouseClick += MyVoidMouseClick;
        }
        

        private void MyVoidMouseClick(Object sender, MouseEventArgs e)
        {
            foreach (Control c in this.Controls)
            {
                if (c.GetType().Name == "Button" && c.Bounds.Contains(e.Location))
                {
                    if (c == button1)
                    {
                        MessageBox.Show("не пикай 1");
                        button1_Click(sender, e);
                    }
                    else if (c == button2)
                    {
                        MessageBox.Show("не пикай 2");
                        button2_Click(sender, e);
                    }
                }
            }

            foreach (Control c in this.Controls)
            {
                if (c.GetType().Name == "Button")
                {
                    c.Enabled = true;
                }
            }
        }


        private void myForm_Load(object sender, EventArgs e)
        {
            BackColor = Color.AntiqueWhite;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            button1.Enabled = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            button2.Enabled = false;
        }        
    }
}