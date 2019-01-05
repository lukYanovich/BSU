using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Xml.Serialization;

namespace _2
{
    public partial class UserInformation : Form
    {
        public UserInformation(Authrorization frm)
        {
            InitializeComponent();
            groupBox1.Text = "Information on \"" + frm.list[frm.position].Name + '\"';
            textBox1.Text = frm.list[frm.position].Name;
            textBox2.Text = frm.list[frm.position].LastName;
            textBox3.Text = frm.list[frm.position].e_mail;
            textBox1.Enabled = textBox2.Enabled = textBox3.Enabled = false;
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            textBox1.Enabled = true;
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            textBox2.Enabled = true;
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            textBox3.Enabled = true;
        }

        private void Exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Logout_Click(object sender, EventArgs e)
        {
            Authrorization frm = (Authrorization)Owner;
            frm.list[frm.position].Name = textBox1.Text;
            frm.list[frm.position].LastName = textBox2.Text;
            frm.list[frm.position].e_mail = textBox3.Text;
            XmlSerializer formatter = new XmlSerializer(typeof(List<Person>));
            try
            {
                FileStream file = new FileStream(@"C:\Projekts\C#\лабораторные\lab 5\2\2\Login_Password.xml", FileMode.Create);
                formatter.Serialize(file, frm.list);
                file.Close();
            }
            catch { }
            this.Close();
        }
    }
}
