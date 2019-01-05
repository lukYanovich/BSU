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
    public partial class Form1_3 : Form
    {
        private PictureBox pic = new PictureBox();

        Pen MyPen = new Pen(Color.Red, 5);
        double angle = 0.0;
        float x = 300, y = 180;
        float x_radius = 150, y_radius = 90, _x = 400, _y = 180;
        float fi = 0;
            
        Image myIMG = Image.FromFile(@"C:\Projects\FAMCS\2sem\УП\C#\lab 4\myIMG.png");
        Image bg = Image.FromFile(@"C:\Projects\FAMCS\2sem\УП\C#\lab 4\background.png");

        private void timer1_Tick(object sender, EventArgs e)
        {
            angle += 0.1;
            _x = x + x_radius * (float)Math.Cos(angle);
            _y = y - y_radius * (float)Math.Sin(angle);
           pic.Refresh();
        }

        private void Form1_3_Load(object sender, EventArgs e)
        {
            pic.Dock = DockStyle.Fill;
            pic.BackColor = Color.White;
            pic.Paint += new System.Windows.Forms.PaintEventHandler(this.pic_Paint);
            this.Controls.Add(pic);     
        }        

        public Form1_3()
        {
            InitializeComponent();
        }

        private void pic_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.Clear(Color.White);
            e.Graphics.DrawImage(bg, 0, 0);
            e.Graphics.TranslateTransform(x, y);
            e.Graphics.RotateTransform(fi);
            e.Graphics.TranslateTransform(-x, -y);
            e.Graphics.DrawImage(myIMG, _x, _y);
            fi += 10;
        }
    }
}