using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank_Management_System
{
    abstract class CreateAccount
    {
        public readonly string first_name;
        public readonly string last_name;
        public readonly string address;
        public long phone;
        public readonly string email;
        public readonly string ID;
        public double balance;

        public double GetBalance()
        {
            return balance;
        }
        public void PrintAccount()
        {

            Console.WriteLine("First Name : " + first_name);
            Console.WriteLine("Last Name : "+last_name);
            Console.WriteLine("Address :" + address);
            Console.WriteLine("Phone : " + phone);
            Console.WriteLine("Email :" + email);
        }
        public CreateAccount()
        {

        }
         public CreateAccount(string first_name, string last_name, string address, long phone,string email)
         {
            this.first_name = first_name;
            this.last_name = last_name;
            this.address = address;
            this.phone = phone;
            this.email = email;
         }
    }
}
