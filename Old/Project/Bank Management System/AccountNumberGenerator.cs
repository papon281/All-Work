using System;
using System.Collections.Generic;
using System.Text;

namespace Bank_Management_System
{
    class AccountNumberGenerator
    {
        //taking system date to create an id for an account holder
        static int id = 10000;
        string storeId;
        //DateTime date = DateTime.Now;

        public string Generate()
        {
            storeId = Convert.ToString(++id);
            return storeId;

        }
    }
}
