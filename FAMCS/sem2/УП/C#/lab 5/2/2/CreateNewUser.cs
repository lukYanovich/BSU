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
    public partial class CreateNewUser : Form
    {
        public CreateNewUser()
        {
            InitializeComponent();
            textBox_Password.PasswordChar = '*';
            textBox_ConfimPassword.PasswordChar = '*';

            textBox_Username.Text = "0";
            textBox_Password.Text = "0";
            textBox_ConfimPassword.Text = "0";
        }

        private void Cancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Create_Click(object sender, EventArgs e)
        {
            try
            {
                string name = textBox_Username.Text;
                string pass = textBox_Password.Text;
                string pass_1 = textBox_ConfimPassword.Text;
                if (name == "0" || pass == "0" || pass_1 == "0")
                    throw new Exception("the fields are not filled!");
                if (pass != pass_1)
                    throw new Exception("the passwords do not match!");

                Authrorization frm = (Authrorization)Owner;
                XmlSerializer formatter = new XmlSerializer(typeof(List<Person>));
                try
                {
                    FileStream file = new FileStream(@"C:\Projekts\C#\лабораторные\lab 5\2\2\Login_Password.xml", FileMode.Open);
                    frm.list = (List<Person>)formatter.Deserialize(file);
                    file.Close();
                }
                catch { frm.list.Clear(); }

                Person person = new Person(name, pass);

                for (int i = 0; i < frm.list.Count; i++)
                    if (frm.list[i].Name == person.Name)
                        throw new Exception("such a person already has.");

                frm.list.Add(person);
                try
                {
                    FileStream file = new FileStream(@"C:\Projekts\C#\лабораторные\lab 5\2\2\Login_Password.xml", FileMode.Create);
                    formatter.Serialize(file, frm.list);
                    file.Close();
                }
                catch { }
                this.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }
    }
}