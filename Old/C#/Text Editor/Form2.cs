using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Text_Editor
{
    public partial class Registration : Form
    {
        private TextBox user, pass, retypepass, firstname, lastname;
        private ComboBox usertype;
        private DateTimePicker datetime;
        private string line;
        public Registration()
        {
            InitializeComponent();
            createtextbox();
            createdatetimepicker();
            createlabel();
            createcombobox();
            createbutton();
            this.Closing += new CancelEventHandler(newuser);
        }

        private void newuser(object sender, CancelEventArgs e)
        {
            e.Cancel = false;
            Login login = new Login();
            this.Hide();
            login.Show();
        }

        private void Registration_Load(object sender, EventArgs e)
        {
            this.Text = "User Registration";
            this.Size = new Size(550, 500);
            this.BackColor = Color.AliceBlue;
        }

        private void createlabel()
        {
            Label username = new Label();
            username.Text = "Username";
            username.Location = new Point(100, 50);
            username.AutoSize = true;
            username.Font = new Font("Times New Roman", 10);
            username.ForeColor = Color.Green;
            username.Padding = new Padding(10);
            this.Controls.Add(username);

            Label password = new Label();
            password.Text = "Password";
            password.Location = new Point(100, 100);
            password.AutoSize = true;
            password.Font = new Font("Times New Roman", 10);
            password.ForeColor = Color.Green;
            password.Padding = new Padding(10);
            this.Controls.Add(password);

            Label retypepassword = new Label();
            retypepassword.Text = "Re-Enter Password";
            retypepassword.Location = new Point(100, 150);
            retypepassword.AutoSize = true;
            retypepassword.Font = new Font("Times New Roman", 10);
            retypepassword.ForeColor = Color.Green;
            retypepassword.Padding = new Padding(10);
            this.Controls.Add(retypepassword);

            Label firstname = new Label();
            firstname.Text = "First Name";
            firstname.Location = new Point(100, 200);
            firstname.AutoSize = true;
            firstname.Font = new Font("Times New Roman", 10);
            firstname.ForeColor = Color.Green;
            firstname.Padding = new Padding(10);
            this.Controls.Add(firstname);

            Label lastname = new Label();
            lastname.Text = "Last Name";
            lastname.Location = new Point(100, 250);
            lastname.AutoSize = true;
            lastname.Font = new Font("Times New Roman", 10);
            lastname.ForeColor = Color.Green;
            lastname.Padding = new Padding(10);
            this.Controls.Add(lastname);

            Label datetime = new Label();
            datetime.Text = "Date of Birth";
            datetime.Location = new Point(100, 300);
            datetime.AutoSize = true;
            datetime.Font = new Font("Times New Roman", 10);
            datetime.ForeColor = Color.Green;
            datetime.Padding = new Padding(10);
            this.Controls.Add(datetime);

            Label usertype = new Label();
            usertype.Text = "User-Type";
            usertype.Location = new Point(100, 350);
            usertype.AutoSize = true;
            usertype.Font = new Font("Times New Roman", 10);
            usertype.ForeColor = Color.Green;
            usertype.Padding = new Padding(10);
            this.Controls.Add(usertype);

        }

        private void createtextbox()
        {
            user = new TextBox();
            user.Location = new Point(300, 60);
            user.AutoSize = true;
            user.Font = new Font("Times New Roman", 10);
            user.Padding = new Padding(10);
            user.BackColor = Color.AntiqueWhite;
            user.Text = "";
            this.Controls.Add(user);

            pass = new TextBox();
            pass.Location = new Point(300, 110);
            pass.AutoSize = true;
            pass.Font = new Font("Times New Roman", 10);
            pass.Padding = new Padding(10);
            pass.PasswordChar = '*';
            pass.BackColor = Color.AntiqueWhite;
            this.Controls.Add(pass);

            retypepass = new TextBox();
            retypepass.Location = new Point(300, 160);
            retypepass.AutoSize = true;
            retypepass.Font = new Font("Times New Roman", 10);
            retypepass.Padding = new Padding(10);
            retypepass.BackColor = Color.AntiqueWhite;
            retypepass.PasswordChar = '*';
            this.Controls.Add(retypepass);

            firstname = new TextBox();
            firstname.Location = new Point(300, 210);
            firstname.AutoSize = true;
            firstname.Font = new Font("Times New Roman", 10);
            firstname.Padding = new Padding(10);
            firstname.BackColor = Color.AntiqueWhite;
            this.Controls.Add(firstname);

            lastname = new TextBox();
            lastname.Location = new Point(300, 260);
            lastname.AutoSize = true;
            lastname.Font = new Font("Times New Roman", 10);
            lastname.Padding = new Padding(10);
            lastname.BackColor = Color.AntiqueWhite;
            this.Controls.Add(lastname);
        }

        private void createdatetimepicker()
        {
            datetime = new DateTimePicker();
            datetime.Location = new Point(300,310);
            datetime.Font = new Font("Times New Roman", 10);
            datetime.AutoSize = true;
            datetime.Padding = new Padding(10);
            datetime.Value = DateTime.Today;
            this.Controls.Add(datetime);
        }


        private void createcombobox()
        {
            usertype = new ComboBox();
            usertype.Location = new Point(300, 360);
            usertype.Items.Insert(0,"View");
            usertype.SelectedIndex = 0;
            usertype.Items.Add("Edit");
            this.Controls.Add(usertype);
        }

        private void createbutton()
        {
            Button submit = new Button();
            submit.Text = "Submit";
            submit.AutoSize = true;
            submit.BackColor = Color.Green;
            submit.Location = new Point(200, 400);
            submit.Font = new Font("Times New Roman", 10);
            submit.Padding = new Padding(6);
            submit.Click += new EventHandler(submit_click);
            this.Controls.Add(submit);

            Button cancel = new Button();
            cancel.Text = "Cancel";
            cancel.AutoSize = true;
            cancel.BackColor = Color.Red;
            cancel.Location = new Point(350, 400);
            cancel.Font = new Font("Times New Roman", 10);
            cancel.Padding = new Padding(6);
            cancel.Click += new EventHandler(cancel_click);
            this.Controls.Add(cancel);
        }

        private void submit_click(Object sender, EventArgs e)
        {
            string directory = Directory.GetCurrentDirectory();
            string filename = directory+"\\login.txt";
            string username = user.Text;
            string password = pass.Text;
            string retypepassword = retypepass.Text;
            string Firstname = firstname.Text;
            string Lastname = lastname.Text;
            string userType = usertype.Text;
            string date = datetime.Value.ToString("dd-MM-yyyy");
            bool found = false;
            if ((password.Equals(retypepassword)) && (username != ""))
            {
                if (!File.Exists(filename))
                {
                    {
                        string text = username + "," + password + "," + userType + "," + Firstname + "," + Lastname + "," + date + Environment.NewLine;
                        File.WriteAllText(filename, text);
                        MessageBox.Show("Account created Succesfully!!");
                        Login login = new Login();
                        this.Hide();
                        login.Show();
                    }
                    
                }
                else
                {
                    string line = File.ReadAllText(filename);
                    string[] lines = line.Split(new string[] { Environment.NewLine }, StringSplitOptions.None);
                    foreach (string contain in lines)
                    {
                        string[] match = contain.Split(new string[] { "," }, StringSplitOptions.None);
                        if (username != "" && password != "")
                        {
                            if (username == match[0])
                            {
                                found = true;
                                break;
                            }
                        }
                    }
                    if (found)
                    {
                        MessageBox.Show("Username is using by other person!!");
                    }
                    else
                    {
                        string text = username + "," + password + "," + userType + "," + Firstname + "," + Lastname + "," + date + Environment.NewLine;
                        File.AppendAllText(filename, text);
                        MessageBox.Show("Account created Succesfully!!");
                        Login login = new Login();
                        this.Hide();
                        login.Show();
                    }
                    
                }

            }
            else
            {
                MessageBox.Show("Your password Doesn't match or username is null.");
            }
        }

        private void cancel_click(Object sender, EventArgs e)
        {
            Login login = new Login();
            this.Hide();
            login.Show();
        }
    }
}
