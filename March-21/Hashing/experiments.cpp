// Name:
#include<iostream>
#include "hash_function.h"

using namespace std;

int main()
{
    int choice;
    Hash h = Hash(1999);
    while(true)
    {
        cout << "Select the load factor for your table" <<endl;
        cout <<"1. For 0.2 load factor" <<endl;
        cout <<"2. For 0.5 load factor" <<endl;
        cout <<"3. For 0.8 load factor" << endl;
        cout <<"4. Exit"<<endl;
        int _choice;
        cout<<"Enter the choice: ";
        cin >> _choice;
        if(_choice == 1)
        {

            while(true)
            {

                cout<<"Operations of Hash Table"<<endl;
                cout<<"1.Insert value into the table"<<endl;
                cout<<"2.Search element from the table"<<endl;
                cout<<"3.Exit"<<endl;
                cout<<"Enter the choice: ";

                cin>>choice;

                if(choice == 1)
                {
                    h.getKey(0.2);
                }

                if(choice == 2)
                {
                    int value;
                    cout<<"Enter value for search: ";
                    cin >> value;
                    if(h.linearSearch(value) == -1)
                    {
                        cout << "The value " << value << " is not found" << endl;
                    }
                    else
                    {
                        cout << "The Element "<< value << " is found in linear probing hashing" << endl;
                    }

                    if(h.quadraticSearch(value) == -1)
                    {
                        cout << "The value " << value << " is not found" << endl;
                    }
                    else
                    {
                        cout << "The Element "<< value << " is found in quadratic probing hashing" << endl;
                    }

                    if(h.doubleSearch(value) == -1)
                    {
                        cout << "The value " << value << " is not found" << endl;
                    }
                    else
                    {
                        cout << "The Element "<< value << " is found in double probing hashing" << endl;
                    }
                }

                if(choice == 3)
                {
                    exit(1);
                }

                else
                {
                    cout << "Please enter number between 1-3" << endl;
                }
            }
        }

        if(_choice == 2)
        {

            while(true)
            {

                cout<<"Operations of Hash Table"<<endl;
                cout<<"1.Insert value into the table"<<endl;
                cout<<"2.Search element from the table"<<endl;
                cout<<"3.Exit"<<endl;
                cout<<"Enter the choice: ";

                cin>>choice;

                if(choice == 1)
                {
                    h.getKey(0.5);
                }

                if(choice == 2)
                {
                    int value;
                    cout<<"Enter value for search: ";
                    cin >> value;
                    if(h.linearSearch(value) == -1)
                    {
                        cout << "The value " << value << " is not found" << endl;
                    }
                    else
                    {
                        cout << "The Element "<< value << " is found in linear probing hashing" << endl;
                    }

                    if(h.quadraticSearch(value) == -1)
                    {
                        cout << "The value " << value << " is not found" << endl;
                    }
                    else
                    {
                        cout << "The Element "<< value << " is found in quadratic probing hashing" << endl;
                    }

                    if(h.doubleSearch(value) == -1)
                    {
                        cout << "The value " << value << " is not found" << endl;
                    }
                    else
                    {
                        cout << "The Element "<< value << " is found in double probing hashing" << endl;
                    }
                }

                if(choice == 3)
                {
                    exit(1);
                }

                else
                {
                    cout << "Please enter number between 1-3" << endl;
                }
            }
        }

        if(_choice == 3)
        {
            while(true)
            {

                cout<<"Operations of Hash Table"<<endl;
                cout<<"1.Insert value into the table"<<endl;
                cout<<"2.Search element from the table"<<endl;
                cout<<"3.Exit"<<endl;
                cout<<"Enter the choice: ";

                cin>>choice;

                if(choice == 1)
                {
                    h.getKey(0.8);
                }

                if(choice == 2)
                {
                    int value;
                    cout<<"Enter value for search: ";
                    cin >> value;
                    if(h.linearSearch(value) == -1)
                    {
                        cout << "The value " << value << " is not found" << endl;
                    }
                    else
                    {
                        cout << "The Element "<< value << " is found in linear probing hashing" << endl;
                    }

                    if(h.quadraticSearch(value) == -1)
                    {
                        cout << "The value " << value << " is not found" << endl;
                    }
                    else
                    {
                        cout << "The Element "<< value << " is found in quadratic probing hashing" << endl;
                    }

                    if(h.doubleSearch(value) == -1)
                    {
                        cout << "The value " << value << " is not found" << endl;
                    }
                    else
                    {
                        cout << "The Element "<< value << " is found in double probing hashing" << endl;
                    }
                }

                if(choice == 3)
                {
                    exit(1);
                }

                else
                {
                    cout << "Please enter number between 1-3." << endl;
                }
            }
        }
        if(_choice == 4)
        {
            exit(0);
        }

        else
        {
            cout << "Please enter number between 1-4." << endl;
        }
    }
    return 0;
}
