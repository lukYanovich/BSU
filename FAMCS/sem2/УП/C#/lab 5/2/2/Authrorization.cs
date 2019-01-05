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
    [Serializable]
    public class Person
    {
        public string Name { get; set; }
        public string Password { get; set; }
        public string NameForChange { get; set; }
        public string LastName { get; set; }
        public string e_mail { get; set; }

        public Person() { }
        public Person(Person a)
        {
            Name = a.Name;
            Password = a.Password;
            NameForChange = a.NameForChange;
            LastName = a.LastName;
            e_mail = a.e_mail;
        }
        public Person(string a, string b)
        {
            Name = a;
            Password = b;
            NameForChange = LastName = e_mail = "empty";
        }
    }
     
    public partial class Authrorization : Form
    {
        public List<Person> list = new List<Person>();
        public int position;

        public Authrorization()
        {
            InitializeComponent();
            textBox_User.Text = "0";
            textBox_Password.Text = "0";
            textBox_Password.PasswordChar = '*';
        }

        private void Create_user_Click(object sender, EventArgs e)
        {
            CreateNewUser frm = new CreateNewUser();
            frm.ShowDialog(this);
        }

        private void Exit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void OK_Click(object sender, EventArgs e)
        {
            if (list.Count == 0)
            {
                XmlSerializer formatter = new XmlSerializer(typeof(List<Person>));
                try
                {
                    FileStream file = new FileStream(@"C:\Projekts\C#\лабораторные\lab 5\2\2\Login_Password.xml", FileMode.Open);
                    list = (List<Person>)formatter.Deserialize(file);
                    file.Close();
                }
                catch { list.Clear(); }
            }

            for (int i = 0; i < list.Count; i++)
            {
                if (list[i].Name == textBox_User.Text)
                {
                    if (list[i].Password != textBox_Password.Text)
                    {
                        MessageBox.Show("wrong password!");
                        return;
                    }
                    else
                    {
                        position = i;
                        UserInformation frm = new UserInformation(this);
                        frm.ShowDialog(this);
                        break;
                    }
                }
                else if(i==(list.Count-1))
                {
                    MessageBox.Show("there is no such person!");
                    return;
                }
            }
        }
    }
}
