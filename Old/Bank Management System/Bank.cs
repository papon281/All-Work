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
    class Bank
    {
        private string id;//hold generated id from AccountNumberGenerator
        AccountNumberGenerator accountnumber = new AccountNumberGenerator();

        public void CreateAccount()
        {

            string firstname;
            string lastname;
            string Address;
            long Phone;
            string Email;

            id = accountnumber.Generate();//collect id from id generator
            string directory = Directory.GetCurrentDirectory();
            string filename = directory + "\\" + Convert.ToString(id) + ".txt";

            while (File.Exists(filename))
            {
                id = accountnumber.Generate();
                filename = directory + "\\" + Convert.ToString(id) + ".txt";
            }

            Console.WriteLine("CREATE A NEW ACCOUNT");
            Console.WriteLine();
            Console.WriteLine("ENTER THE DETAILS");
            Console.WriteLine();

            Console.Write("First Name: ");
            firstname = Convert.ToString(Console.ReadLine());

            Console.Write("Last Name: ");
            lastname = Convert.ToString(Console.ReadLine());

            Console.Write("Address: ");
            Address = Convert.ToString(Console.ReadLine());

            Console.Write("Phone: ");
            Phone = Convert.ToInt64(Console.ReadLine());

            Console.Write("Email: ");
            Email = Convert.ToString(Console.ReadLine());

            Console.Write("Is the information correct (y/n)? ");
            string t = Console.ReadLine();
            if (string.Compare(t, "y") == 0)
            {
                Console.WriteLine();
                Console.WriteLine("Account created! Details will be provided via Email!!!");
                Console.WriteLine();
                Console.WriteLine("Your account number is : " + id);

                if (!File.Exists(filename))
                {

                    string createtext = firstname + Environment.NewLine + lastname + Environment.NewLine + Address + Environment.NewLine + Phone + Environment.NewLine + Email + Environment.NewLine +"0" + Environment.NewLine;
                    File.WriteAllText(filename, createtext);
                    sendEmail(Email, id, "Account number");
                }
            }
            else
            {
                Console.WriteLine("Account create unsuccessfull!!");
            }

        }

        public void SearchAccount()
        {

            Console.WriteLine("SEARCH AN ACCOUNT");
            Console.WriteLine();
            Console.WriteLine("ENTER THE DETAILS");
            Console.WriteLine();

            Console.Write("Account Number: ");
            string inId = Convert.ToString(Console.ReadLine());
            Console.WriteLine();

            string directory = Directory.GetCurrentDirectory();
            string filename = directory + "\\" + Convert.ToString(inId) + ".txt";

            if (File.Exists(filename))
            {
                Console.WriteLine("Account Found!!");
                Console.WriteLine();
                Console.WriteLine("Account Details");
                Console.WriteLine();

                Console.WriteLine("Account No: " + inId);
                string line = File.ReadAllText(filename);
                string[] lines = line.Split(Environment.NewLine,StringSplitOptions.RemoveEmptyEntries);
                Console.WriteLine("Account Balance: $$" + lines[5]);
                Console.WriteLine("First Name: " + lines[0]);
                Console.WriteLine("Last Name: " + lines[1]);
                Console.WriteLine("Address: " + lines[2]);
                Console.WriteLine("Phone: " + (Convert.ToInt64(lines[3])));
                Console.WriteLine("Email: " + lines[4]); 

                Console.WriteLine();
                Console.Write("Check another account (y/n)? ");
                string t = Console.ReadLine();
                if (string.Compare(t, "y") == 0)
                {
                    SearchAccount();
                }
            }
            else
            {
                Console.WriteLine("Account not Found!!");
            }
        }

        public void Deposit()
        {
            Console.WriteLine("DEPOSIT");
            Console.WriteLine("ENTER THE DETAILS");
            Console.WriteLine();

            Console.Write("Account Number: ");
            string inId = Convert.ToString(Console.ReadLine());
            string directory = Directory.GetCurrentDirectory();
            string filename = directory + "\\" + Convert.ToString(inId) + ".txt";

            if (File.Exists(filename))
            {
                Console.WriteLine("Account Found!! Enter the amount.....");
                Console.Write("Amount: $$");
                double depositbalance = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine("Deposit successfull");

                string line = File.ReadAllText(filename);
                var lines = line.Split(Environment.NewLine,StringSplitOptions.RemoveEmptyEntries);
                double newbalance = Convert.ToDouble(lines[5])+depositbalance;
                lines[5] = Convert.ToString(newbalance);
                File.WriteAllLines((filename),lines.ToArray());

                string appendtext = "Deposit: $$"+Convert.ToString(depositbalance) + Environment.NewLine;
                File.AppendAllText(filename, appendtext);

            }
            else
            {
                Console.WriteLine("Account not found!!!");
                Console.Write("Retry (y/n)? ");
                string t = Console.ReadLine();
                if (string.Compare(t, "y") == 0)
                {
                    Deposit();
                }
            }
        }

        public void Withdraw()
        {
            Console.WriteLine("WITHDRAW");
            Console.WriteLine("ENTER THE DETAILS");

            Console.Write("Account Number: ");
            string inId = Convert.ToString(Console.ReadLine());
            string directory = Directory.GetCurrentDirectory();
            string filename = directory + "\\" + Convert.ToString(inId) + ".txt";

            if (File.Exists(filename))
            {
                Console.WriteLine("Account Found!! Enter the amount....");
                Console.Write("Amount: $$");
                double withdrawbalance = Convert.ToDouble(Console.ReadLine());
                string line = File.ReadAllText(filename);
                var lines = line.Split(Environment.NewLine, StringSplitOptions.RemoveEmptyEntries);
                double totalbalance = Convert.ToDouble(lines[5]);
                if (totalbalance<withdrawbalance)
                {
                    Console.WriteLine("Your Balance is Low!! Please deposit");
                }
                else
                {
                    Console.WriteLine("Withdraw successfull");
                    string appendtext = "Withdraw: $$" + Convert.ToString(withdrawbalance) + Environment.NewLine;
                    totalbalance = totalbalance - withdrawbalance;
                    lines[5] = Convert.ToString(totalbalance);
                    File.WriteAllLines((filename), lines.ToArray());
                    File.AppendAllText(filename, appendtext);
                }
            }

            else
            {
                Console.WriteLine("Account not found!");
            }
        }
        public void Statement()
        {
            Console.WriteLine("STATEMENT");
            Console.WriteLine("ENTER THE DETAILS");
            Console.WriteLine();

            Console.Write("Account Number: ");
            string inId = Convert.ToString(Console.ReadLine());

            string directory = Directory.GetCurrentDirectory();
            string filename = directory + "\\" + Convert.ToString(inId) + ".txt";

            if (File.Exists(filename))
            {
                Console.WriteLine("Account Found!! The statement is displayed below!!");
                Console.WriteLine();
                Console.WriteLine("Simple Banking System");
                Console.WriteLine();

                Console.WriteLine("Account statement");
                Console.WriteLine();

                Console.WriteLine("Account No: " + inId);
                string line = File.ReadAllText(filename);
                var lines = line.Split(Environment.NewLine, StringSplitOptions.RemoveEmptyEntries);
                int length = lines.Length;
                Console.WriteLine("Balance: $$" + lines[5]);
                Console.WriteLine("First Name: " + lines[0]);
                Console.WriteLine("Last Name: " + lines[1]);
                Console.WriteLine("Address: " + lines[2]);
                Console.WriteLine("Phone: " + (Convert.ToInt64(lines[3])));
                Console.WriteLine("Email: " + lines[4]);

                //Console.WriteLine("Length "+length);
                int countStatement =length - 6;
                // Console.WriteLine("Satement "+countStatement);
                string statement = "";
                if (countStatement>=1 && countStatement <= 5)
                {
                    for(int i = 6; i < length; i++)
                    {
                        Console.WriteLine(lines[i]);
                        statement += lines[i] + Environment.NewLine;
                    }
                }
                else if(countStatement>5)
                {
                    countStatement = (countStatement - 5);
                    int StartIndex = 6+countStatement;
                   // Console.WriteLine("StartIndex "+StartIndex);
                    for (int i = StartIndex; i <length; i++)
                    {
                        Console.WriteLine(lines[i]);
                        statement += lines[i] + Environment.NewLine;
                    }
                }

                Console.Write("Email statement (y/n)? ");
                string t = Console.ReadLine();
                if (string.Compare(t, "y") == 0)
                {
                    sendEmail(lines[4], statement, "A\\C Statement");
                    Console.WriteLine("Email sent successfully!!!");
                }
            }
            else
            {
                Console.WriteLine("Account not Found!!");
            }
        }

        public void Delete()
        {
            Console.WriteLine("DELETE AN ACCOUNT");
            Console.WriteLine("ENTER THE DETAILS");
            Console.WriteLine();

            Console.Write("Account Number: ");
            string inId = Convert.ToString(Console.ReadLine());
            string directory = Directory.GetCurrentDirectory();
            string filename = directory + "\\" + Convert.ToString(inId) + ".txt";
            if (File.Exists(filename))
            {
                Console.WriteLine("Account Found!! Details displayed below....");
                Console.WriteLine();
                Console.WriteLine("ACCOUNT DETAILS");
                Console.WriteLine();

                string line = File.ReadAllText(filename);
                var lines = line.Split(Environment.NewLine, StringSplitOptions.RemoveEmptyEntries);
                int length = lines.Length;

                Console.WriteLine("Account No: " + inId);
                Console.WriteLine("Balance: $$" + lines[5]);
                Console.WriteLine("First Name: " + lines[0]);
                Console.WriteLine("Last Name: " + lines[1]);
                Console.WriteLine("Address: " + lines[2]);
                Console.WriteLine("Phone: " + (Convert.ToInt64(lines[3])));
                Console.WriteLine("Email: " + lines[4]);

                Console.WriteLine();
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
        public void sendEmail(string toEmail, string body, string subject)
        {
            MailAddress to = new MailAddress(toEmail);
            MailAddress from = new MailAddress("cprogg780@gmail.com"); // Cprogram1
            MailMessage mail = new MailMessage(from, to);
            mail.Subject = subject;
            mail.Body = body;
            SmtpClient smtp = new SmtpClient();
            smtp.Host = "smtp.gmail.com";
            smtp.Port = 587;
            smtp.UseDefaultCredentials = false;
            smtp.Credentials= new NetworkCredential("cprogg780@gmail.com", "Cprogram1");
            smtp.EnableSsl = true;
            smtp.DeliveryMethod = SmtpDeliveryMethod.Network;
            Console.WriteLine("Sending mail...");
            try
            {
                smtp.Send(mail);
            }
            catch (SmtpFailedRecipientsException ex)
            {
                for (int i = 0; i < ex.InnerExceptions.Length; i++)
                {
                    SmtpStatusCode status = ex.InnerExceptions[i].StatusCode;
                    if (status == SmtpStatusCode.MailboxBusy ||
                        status == SmtpStatusCode.MailboxUnavailable)
                    {
                        Console.WriteLine("Delivery failed - retrying in 5 seconds.");
                        System.Threading.Thread.Sleep(5000);
                        smtp.Send(mail);
                    }
                    else
                    {
                        Console.WriteLine("Failed to deliver message to {0}",
                            ex.InnerExceptions[i].FailedRecipient);
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception caught in RetryIfBusy(): {0}",ex.ToString());
            }
        }

    }
}
