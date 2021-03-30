using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Globalization;

namespace Bank_Management_System
{
    class Bank
    {
        string id;//hold generated id from AccountNumberGenerator
        public int idnum = 0;//index number for id
        //hold separated id in separated index
        public string[] myId = new string[100];
        public double mybalance = 0.0;

        AccountNumberGenerator accountnumber = new AccountNumberGenerator();
        //see in create account
        public bool val = true;
        public bool debval = true;

        //id storing
        private void GetAcc(string ID)
        {
           ID = this.id;
           myId[idnum] = ID;
           idnum++;
        }

        public void Create_account()
        {

            string firstname;
            string lastname;
            string Address;
            long Phone;
            string Email;

            id = accountnumber.Generate();//collect id from id generator
            string id_file = Convert.ToString(id) + ".txt";
            string filename = "F:\\Bank Management System\\" + id_file;

            Console.WriteLine("Create a new account");
            Console.WriteLine("Enter the details");

            Console.Write("Enter First Name: ");
            firstname = Convert.ToString(Console.ReadLine());

            Console.Write("Enter Last Name: ");
            lastname = Convert.ToString(Console.ReadLine());

            Console.Write("Enter Address: ");
            Address = Convert.ToString(Console.ReadLine());

            Console.Write("Enter Phone number: ");
            Phone = Convert.ToInt64(Console.ReadLine());

            Console.Write("Enter Email: ");
            Email = Convert.ToString(Console.ReadLine());

            Console.WriteLine("Your account is created successfully");
            Console.WriteLine("Your Account Id : " + id);
            GetAcc(id);//store id and increase the index number

            if (!File.Exists(filename))
            { 
                string createtext =firstname + " " + lastname + " " + " " + Address + " " + Phone + " " + Email + Environment.NewLine;
                File.WriteAllText(filename,createtext);
            }
        }

        public void SearchAccount()
        {

            Console.WriteLine("Search for an account");
            Console.WriteLine();
            Console.WriteLine("Enter Details");
            Console.WriteLine();
            Console.Write("account No : ");
            string inId = Convert.ToString(Console.ReadLine());
            string idfile=inId+".txt";
            string filename = "F:\\Bank Management System\\" +idfile;
            if (File.Exists(filename))
            {
                Console.WriteLine("Account Found!!");
                Console.WriteLine("Account Details");
                Console.WriteLine("Account No: " + inId);
                string line = File.ReadAllText(filename);
                var lines= line.Split((string[])null, StringSplitOptions.RemoveEmptyEntries);
                int length = lines.Length;
                if (length == 5)
                {
                    Console.WriteLine("First Name: " + lines[0]);
                    Console.WriteLine("Last Name: " + lines[1]);
                    Console.WriteLine("Address: " + lines[2]);
                    Console.WriteLine("Phone: " + Convert.ToInt64(lines[3]));
                    Console.WriteLine("First Name: " + lines[4]);
                }
                else
                {
                    Console.WriteLine("First Name: " + lines[0]);
                    Console.WriteLine("Last Name: " + lines[1]);
                    Console.WriteLine("Address: " + lines[2]);
                    Console.WriteLine("Phone: " + (Convert.ToInt64(lines[3])));
                    Console.WriteLine("First Name: " + lines[4]);
                    Console.WriteLine("Balance: $$" + lines[5]);
                }
            }
            else
            {
                Console.WriteLine("Account not Found!!");
            }
        }

        public void Deposit()
        {
            Console.WriteLine("Deposit");
            Console.WriteLine("ENTER THE DETAILS");

            Console.Write("Account Number: ");
            string inId = Convert.ToString(Console.ReadLine());
            string idfile = inId + ".txt";
            string filename= "F:\\Bank Management System\\"+idfile;

            if (File.Exists(filename))
            {
                Console.WriteLine("Account Found!! Enter the amount....");
                double balance = Convert.ToDouble(Console.ReadLine());
                mybalance = mybalance + balance;
                string line = File.ReadAllText(filename);
                var lines = line.Split((string[])null, StringSplitOptions.RemoveEmptyEntries);
                int length = lines.Length;
                if (length == 5)
                {
                    string appendtext = Convert.ToString(mybalance) + Environment.NewLine;
                    File.AppendAllText(filename, appendtext);
                }
                else
                {
                    mybalance = Convert.ToDouble(lines[length - 1])+balance;
                    lines[length - 1] = Convert.ToString(mybalance);
                    File.WriteAllLines((filename),lines.ToArray());
                }

            }
            else
            {
                Console.WriteLine("Your id is wrong!");
            }
        }

        public void Withdraw()
        {
            Console.WriteLine("Deposit");
            Console.WriteLine("ENTER THE DETAILS");

            Console.Write("Account Number: ");
            string inId = Convert.ToString(Console.ReadLine());
            string idfile = inId + ".txt";
            string filename = "F:\\Bank Management System\\" + idfile;

            if (File.Exists(filename))
            {
                Console.WriteLine("Account Found!! Enter the amount....");
                double balance = Convert.ToDouble(Console.ReadLine());
                mybalance = mybalance + balance;
                string line = File.ReadAllText(filename);
                var lines = line.Split((string[])null, StringSplitOptions.RemoveEmptyEntries);
                int length = lines.Length;
                if (length == 5)
                {
                    Console.WriteLine("Please deposit first");
                }
                else
                {
                    mybalance = Convert.ToDouble(lines[length - 1]);
                    if (mybalance < balance)
                    {
                        Console.WriteLine("Your Balance is Low!! Please kindly deposit...");
                    }
                    else
                    {
                        mybalance = mybalance - balance;
                    }
                    lines[length - 1] = Convert.ToString(mybalance);
                    File.WriteAllLines((filename), lines.ToArray());
                }
            }

            else
            {
                Console.WriteLine("Your id is wrong!");
            }
        }
        public void Statement()
        {
            Console.WriteLine("STATEMENT");
            Console.WriteLine("Enter Details");
            Console.WriteLine();
            Console.Write("account No : ");
            string inId = Convert.ToString(Console.ReadLine());
            string idfile = inId + ".txt";
            string filename = "F:\\Bank Management System\\" + idfile;
            if (File.Exists(filename))
            {
                Console.WriteLine("Account Found!!");
                Console.WriteLine("Account Details");
                Console.WriteLine("Account No: " + inId);
                string line = File.ReadAllText(filename);
                var lines = line.Split((string[])null, StringSplitOptions.RemoveEmptyEntries);
                int length = lines.Length;
                if (length == 5)
                {
                    Console.WriteLine("First Name: " + lines[0]);
                    Console.WriteLine("Last Name: " + lines[1]);
                    Console.WriteLine("Address: " + lines[2]);
                    Console.WriteLine("Phone: " + Convert.ToInt64(lines[3]));
                    Console.WriteLine("First Name: " + lines[4]);
                }
                else
                {
                    Console.WriteLine("First Name: " + lines[0]);
                    Console.WriteLine("Last Name: " + lines[1]);
                    Console.WriteLine("Address: " + lines[2]);
                    Console.WriteLine("Phone: " + (Convert.ToInt64(lines[3])));
                    Console.WriteLine("First Name: " + lines[4]);
                    Console.WriteLine("Balance: $$" + lines[5]);
                }
            }
            else
            {
                Console.WriteLine("Account not Found!!");
            }
        }

        public void Delete()
        {
            Console.WriteLine("DELETE");
            Console.WriteLine("ENTER THE DETAILS");

            Console.Write("Account Number: ");
            Console.WriteLine("Enter Details");
            Console.WriteLine();
            Console.Write("account No : ");
            string inId = Convert.ToString(Console.ReadLine());
            string idfile = inId + ".txt";
            string filename = "F:\\Bank Management System\\" + idfile;
            if (File.Exists(filename))
            {
                Console.WriteLine("Account Found!!");
                Console.WriteLine("Account Details");
                Console.WriteLine("Account No: " + inId);
                string line = File.ReadAllText(filename);
                var lines = line.Split((string[])null, StringSplitOptions.RemoveEmptyEntries);
                int length = lines.Length;
                if (length == 5)
                {
                    Console.WriteLine("First Name: " + lines[0]);
                    Console.WriteLine("Last Name: " + lines[1]);
                    Console.WriteLine("Address: " + lines[2]);
                    Console.WriteLine("Phone: " + Convert.ToInt64(lines[3]));
                    Console.WriteLine("First Name: " + lines[4]);
                }
                else
                {
                    Console.WriteLine("First Name: " + lines[0]);
                    Console.WriteLine("Last Name: " + lines[1]);
                    Console.WriteLine("Address: " + lines[2]);
                    Console.WriteLine("Phone: " + (Convert.ToInt64(lines[3])));
                    Console.WriteLine("First Name: " + lines[4]);
                    Console.WriteLine("Balance: $$" + lines[5]);
                }
                Console.Write("Delete (y/n): ");
                string t = Console.ReadLine();
                if (string.Compare(t, "y") == 0)
                {
                    File.Delete(filename);
                }
            }
            else
            {
                Console.WriteLine("Account not Found!!");
            }

        }

    }
}
