using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Globalization;
using System.Net.Mail;
using System.Net;

namespace Bank_Management_System
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("WELCOME TO SIMPLE BANKING MANAGEMENT SYSTEM");
            Console.WriteLine();
            Console.WriteLine("LOGIN TO START");
            Console.WriteLine();

            string directory = Directory.GetCurrentDirectory();
            string line = File.ReadAllText(directory+"\\login.txt");
            var lines = line.Split((string[])null, StringSplitOptions.RemoveEmptyEntries);
            string[] username=new string[1000];
            string[] password=new string[1000];
            int userindex = 0;
            int passindex = 0;

            for(int i = 0; i < lines.Length; i++)
            {
                if (i + 1 % 2 == 1)
                {
                    username[userindex] = lines[i];
                    userindex++;
                }
                else
                {
                    password[passindex] = lines[i];
                    passindex++;
                }
            }

            string Username;
            string Password;

            bool status = false;
            while (status == false)
            {
                Console.Write("User Name: ");
                Username = Convert.ToString(Console.ReadLine());
                System.Console.Write("password: ");
                Password = null;
                while (true)
                {
                    var key = System.Console.ReadKey(true);
                    Console.Write("*");
                    if (key.Key == ConsoleKey.Enter) 
                    {
                        Console.WriteLine();
                        break;
                    }
                    Password += key.KeyChar;
                }

                if ((username.Contains(Username)) && (password.Contains(Password))){
                    Console.WriteLine("Valid Credentials!! Please enter.....");
                    status = true;
                }
                else
                {
                    Console.WriteLine("Inavlid Credentials!!! Please, enter the valid credentials.");
                }
            }

            int input=0;
            AccountNumberGenerator Account = new AccountNumberGenerator();
            Bank bn = new Bank();
            Console.WriteLine("****  WELCOME TO SIMPLE BANK MANAGEMENT SYSTEM  ***");
            while (true)
            {
                Console.WriteLine("1. Create a new account");
                Console.WriteLine("2. Search for an account");
                Console.WriteLine("3. Deposit");
                Console.WriteLine("4. Withdraw");
                Console.WriteLine("5. A/C Statement");
                Console.WriteLine("6. Delete Account");
                Console.WriteLine("7. Exit");
                Console.Write("Enter Your Choice (1-7): ");
                input = Convert.ToInt32(Console.ReadLine());
                if(input<1 && input > 7)
                {
                    Console.WriteLine("Wrong Input!! Please enter valid number....");
                }

                //for 0-7  funtion calling
                else if (input == 1)
                {
                    bn.CreateAccount();

                }
                else if (input == 2)
                {
                    bn.SearchAccount();
                }
                else if (input == 3)
                {
                    bn.Deposit();
                }
                else if (input == 4)
                {
                    bn.Withdraw();
                }
                else if (input == 5)
                {
                    bn.Statement();
                }
                else if (input == 6)
                {
                   bn.Delete();
                }
                else if (input == 7)
                {
                    break;
                }
            }
        }
    }
}
