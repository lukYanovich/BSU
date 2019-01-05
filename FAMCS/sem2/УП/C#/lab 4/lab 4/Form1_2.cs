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
    public partial class Form1_2 : Form
    {
        private PictureBox pic = new PictureBox();

        public Form1_2()
        {
            InitializeComponent();
        }

        private void Form1_2_Load(object sender, EventArgs e)
        {
            pic.Dock = DockStyle.Fill;
            pic.BackColor = Color.White;
            pic.Paint += new System.Windows.Forms.PaintEventHandler(this.pic_Paint);
            this.Controls.Add(pic);
        }

        private void pic_Paint(object sender, PaintEventArgs e)
        {
            Rectangle rectangle1 = new Rectangle(50, 50, 200, 100);
            Rectangle rectangle2 = new Rectangle(70, 20, 50, 200);
            e.Graphics.DrawRectangle(Pens.Black, rectangle1);
            e.Graphics.DrawRectangle(Pens.Red, rectangle2);
            if (rectangle1.IntersectsWith(rectangle2))
            {
                rectangle1.Intersect(rectangle2);
                if (!rectangle1.IsEmpty)
                {
                    e.Graphics.FillRectangle(Brushes.Green, rectangle1);
                }
            }
            Rectangle rectangle3 = new Rectangle(350, 50, 200, 120);
            Pen pen = new Pen(Brushes.Red, 3);
            pen.DashStyle = System.Drawing.Drawing2D.DashStyle.Dash;
            e.Graphics.DrawEllipse(pen, rectangle3);


            int n = 5;               // число вершин
            double R = 25, r = 50;   // радиусы
            double alpha = 60;        // поворот
            double x0 = 400, y0 = 260; // центр
            PointF[] points = new PointF[2 * n + 1];
            double a = alpha, da = Math.PI / n, l;
            for (int k = 0; k < 2 * n + 1; k++)
            {
                l = k % 2 == 0 ? r : R;
                points[k] = new PointF((float)(x0 + l * Math.Cos(a)), (float)(y0 + l * Math.Sin(a)));
                a += da;
            }
            e.Graphics.DrawLines(Pens.Black, points);


            int i = 0;
            Pen _pen = new Pen(Brushes.Red, 6);
            Point[] Anarchy = new Point[5];
            Point p1 = new Point(700, 330);
            Point p2 = new Point(670, 200);
            Point p3 = new Point(620, 340);
            Point p4 = new Point(615, 300);
            Point p5 = new Point(720, 280);
            Anarchy[i++] = p1;
            Anarchy[i++] = p2;
            Anarchy[i++] = p3;
            Anarchy[i++] = p4;
            Anarchy[i++] = p5;
            e.Graphics.DrawLines(_pen, Anarchy);
            e.Graphics.DrawEllipse((new Pen(Brushes.Red, 9)), 605, 210, 120, 120);
        }
    }
}