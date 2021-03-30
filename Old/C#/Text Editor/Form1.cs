using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Text_Editor
{
    public partial class Login : Form
    {
        private TextBox user, pass;
        public static string username,userType,password;
        
        public Login()
        {
            InitializeComponent();
            createlabel();
            createtextbox();
            createbutton();
            this.Closing += new CancelEventHandler(Login_cancel);
        }
        private void Login_cancel(object sender,CancelEventArgs e)
        {
            e.Cancel = false;
            Application.Exit();
        }

        private void Login_Load(object sender, EventArgs e)
        {
            this.Text = "User Login";
            this.Size = new Size(500, 400);
            this.BackColor = Color.AliceBlue;
            this.AutoSize = true;
            this.AutoSizeMode = AutoSizeMode.GrowOnly;
        }

        private void createlabel()
        {
            Label username = new Label();
            username.Text = "Username";
            username.Location = new Point(100, 50);
            username.AutoSize = true;
            username.Font = new Font("Times New Roman", 14);
            username.ForeColor = Color.Green;
            username.Padding = new Padding(10);
            this.Controls.Add(username);

            Label password = new Label();
            password.Text = "Password";
            password.Location = new Point(100, 100);
            password.AutoSize = true;
            password.Font = new Font("Times New Roman", 14);
            password.ForeColor = Color.Green;
            password.Padding = new Padding(10);
            this.Controls.Add(password);
        }

        private void createtextbox()
        {
            user = new TextBox();
            user.Location = new Point(250, 60);
            user.AutoSize = true;
            user.Font = new Font("Times New Roman", 10);
            user.Padding = new Padding(10);
            user.BackColor = Color.AntiqueWhite;
            user.Text ="";
            this.Controls.Add(user);

            pass = new TextBox();
            pass.Location = new Point(250, 110);
            pass.AutoSize = true;
            pass.Font = new Font("Times New Roman", 10);
            pass.Padding = new Padding(10);
            pass.BackColor = Color.AntiqueWhite;
            pass.Text ="";
            pass.PasswordChar = '*';
            this.Controls.Add(pass);
        }

        private void createbutton() 
        {
            Button exit = new Button();
            exit.Text = "Exit";
            exit.AutoSize = true;
            exit.BackColor = Color.Red;
            exit.Location = new Point(50, 200);
            exit.Font = new Font("Times New Roman", 10);
            exit.Padding = new Padding(6);
            exit.Click += new EventHandler(exit_Click);
            this.Controls.Add(exit);

            Button login = new Button();
            login.Text = "Login";
            login.AutoSize = true;
            login.BackColor = Color.Green;
            login.Location = new Point(200, 200);
            login.Font = new Font("Times New Roman", 10);
            login.Padding = new Padding(6);
            login.Click += new EventHandler(login_Click);
            this.Controls.Add(login);

            Button newuser = new Button();
            newuser.Text = "New User";
            newuser.AutoSize = true;
            newuser.BackColor = Color.Yellow;
            newuser.Location = new Point(350, 200);
            newuser.Font = new Font("Times New Roman", 10);
            newuser.Padding = new Padding(6);
            newuser.Click += new EventHandler(newuser_Click);
            this.Controls.Add(newuser);
        }

        private void login_Click(Object sender, EventArgs e)
        {
            string directory = Directory.GetCurrentDirectory();
            bool found = false;
            string filename = directory + "\\login.txt";
            username =user.Text;
            password = pass.Text;
            if (File.Exists(filename))
            {
                string line = File.ReadAllText(filename);
                string[] lines = line.Split(new string[]{ Environment.NewLine},StringSplitOptions.None);
                foreach (string contain in lines)
                {
                    string[] match = contain.Split(new string[] { "," }, StringSplitOptions.None);
                    if (username != "" && password != "")
                    { 
                        if (username == match[0] && password == match[1])
                        {
                            found = true;
                            userType = match[2];
                            break;
                        }
                    }
                }
                if (found == true)
                {
                    Texteditor editor = new Texteditor();
                    editor.Show();
                    this.Hide();
                }
                else
                {
                    MessageBox.Show("Username or password is incorrect");
                }
            }
            else
            {
                MessageBox.Show("File not exist!!");
            }
        }


        private void newuser_Click(object sender, EventArgs e)
        {
            Registration register = new Registration();
            this.Hide();
            register.Show();
        }

        private void exit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
