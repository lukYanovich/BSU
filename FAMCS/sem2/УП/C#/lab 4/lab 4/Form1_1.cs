using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace lab_4
{
    public partial class Form1_1 : Form
    {
        public Form1_1()
        {
            InitializeComponent();
        }

        private double Xmin = -5;
        private double Xmax = 5;
        private double Step = 0.1;

        private double[] arrX;
        private double[] arrY;
        Chart chart;

        private double myFunction(double x)
        {
            double y = 0, z = 12;
            double rezult = Math.Abs(Math.Pow(x, y / x) - Math.Pow(y / x, 0.3));
            rezult += (y - x) * (Math.Cos(y) - z / (y - x)) / (1 + (y - x) * (y - x));
            return rezult;
        }

        private void CalcFunction()
        {
            int count = (int)Math.Ceiling((Xmax - Xmin) / Step) + 1;

            arrX = new double[count];
            arrY = new double[count];

            for (int i = 0; i < count; ++i)
            {
                arrX[i] = Xmin + Step * i;
                arrY[i] = myFunction(arrX[i]);
            }
        }

        private void CreateChart()
        {
            chart = new Chart();
            chart.Parent = this;
            chart.SetBounds(10, 10, ClientSize.Width - 20, ClientSize.Height - 20);
            ChartArea area = new ChartArea();
            area.Name = "myGraph";
            area.AxisX.Minimum = Xmin;
            area.AxisX.Maximum = Xmax;
            area.AxisX.MajorGrid.Interval = Step;
            chart.ChartAreas.Add(area);
            Series series1 = new Series();
            series1.ChartArea = "myGraph";
            series1.ChartType = SeriesChartType.Spline;
            series1.BorderWidth = 4;
            series1.LegendText = "f(x). y, z - fixed";
            chart.Series.Add(series1);

            Legend legend = new Legend();
            chart.Legends.Add(legend);
        }

        private void Form1_1_Load(object sender, EventArgs e)
        {
            CreateChart();
            CalcFunction();
            chart.Series[0].Points.DataBindXY(arrX, arrY);
        }
    }
}