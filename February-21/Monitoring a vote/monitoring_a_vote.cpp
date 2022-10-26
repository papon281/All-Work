#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h>
#include<fstream>
#include<utility>
#include<algorithm>
#include<set>
#include<iterator>
#include<vector>
#include<stdio.h>

using namespace std;
int TABLE_SIZE = 0;

class HashNode
{
public:
    int RIN,zipCode;
    string firstName, lastName;
    bool cast_vote;
    HashNode* next;
    HashNode* head;
    HashNode* tail;
    HashNode(int RIN, string firstName, string lastName,int zipCode)
    {
        this->RIN = RIN;
        this->firstName = firstName;
        this->lastName = lastName;
        this->zipCode = zipCode;
        this->cast_vote=false;
        this->next = NULL;
    }
};

class HashMap
{
private:
    HashNode** htable;
public:
    HashMap()
    {
        htable = new HashNode*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            htable[i] = NULL;
    }
    ~HashMap()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            HashNode* entry = htable[i];
            while (entry != NULL)
            {
                HashNode* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] htable;
    }

    int HashFunc(int RIN)
    {
        return RIN % TABLE_SIZE;
    }

    void Insert(int RIN, string firstName, string lastName,int zipCode)
    {
        int hash_val = HashFunc(RIN);
        HashNode* prev = NULL;
        HashNode* entry = htable[hash_val];
        while(entry != NULL)
        {
            prev = entry;
            entry = entry->next;

        }
        if (entry == NULL)
        {
            entry = new HashNode(RIN, firstName,lastName,zipCode);
            if (prev == NULL)
            {
                htable[hash_val] = entry;
            }
            else
            {
                prev->next = entry;
            }
        }
        else
        {
            entry->RIN= RIN;
            entry->firstName = firstName;
            entry->lastName = lastName;
            entry->zipCode = zipCode;
        }

    }

    void Remove(int RIN)
    {
        int hash_val = HashFunc(RIN);
        HashNode* entry = htable[hash_val];
        HashNode *prev = NULL;
        bool flag = false;
        while(entry!=NULL)
        {
            if(entry->RIN==RIN)
            {
                if(prev == NULL){
                    htable[hash_val] = entry->next;
                } else {
                    prev->next = entry->next;
                }
                delete entry;
                entry = NULL;
                flag=true;
                break;
            }
            prev = entry;
            entry = entry->next;
        }
        if(!flag)
        {
            cout<<"Resident id number not found or deleted before"<<endl;
        }
        else
        {
            cout<<"Resident id number deleted"<<endl;
        }

    }

    void Search(int residentid)
    {
        bool flag = false;
        int hash_val = HashFunc(residentid);
        HashNode* entry = htable[hash_val];
        while (entry != NULL)
        {
            if (entry->RIN == residentid)
            {
                cout<<entry->RIN<<" "<<entry->firstName<<" "<<entry->lastName<<" "<<entry->zipCode<<endl;
                flag = true;
                break;
            }
            entry = entry->next;
        }
        if (!flag)
        {
            cout<<"No Element Found"<<endl;
        }
    }

    bool registered_voter(int residentId)
    {
        bool flag = false;
        int hash_val = HashFunc(residentId);
        HashNode* entry = htable[hash_val];
        while(entry != NULL)
        {
            if(entry->RIN == residentId && entry->cast_vote==false)
            {
                entry->cast_vote = true;
                flag = true;
                break;
            }
            entry = entry->next;
        }
        return flag;
    }

    void bulk_vote(string filename)
    {
        string data[4],str;
        ifstream openfile;
        openfile.open(filename);
        if(!openfile.is_open())
        {
            cout<<"File is not open"<<endl;
        }
        else
        {
            while(getline(openfile,str))
            {
                int j=0;
                string tmp="";
                int length = str.length();
                for(int i =0; i<(int)str.length(); i++)
                {
                    if(str[i]==' ')
                    {
                        data[j++] = tmp;
                        tmp = "";
                    }
                    else
                    {
                        tmp = tmp + str[i];
                    }

                }
                data[j++] = tmp;
                int residentId = stoi(data[0]);
                if(!registered_voter(residentId)){
                    cout<<"Already registered"<<endl;
                }
                else{
                    cout<<"Registration complete"<<endl;
                }
            }
        }
        openfile.close();
    }

    int count_voter()
    {
        HashNode* entry = NULL;
        int _count = 0;
        for(int i =0; i<TABLE_SIZE; i++)
        {
            entry = htable[i];
            while(entry!=NULL)
            {
                if(entry->cast_vote==true)
                {
                    _count++;
                }
                entry = entry->next;
            }
        }
        return _count;
    }

    float calculate_percentage()
    {
        int voter = count_voter();
        float percentage = (float)((100*voter)/TABLE_SIZE);
        return percentage;
    }

    void printParticipantId(int Zipcode)
    {
        HashNode* entry = NULL;
        bool found = false;
        for(int i =0; i<TABLE_SIZE; i++)
        {
            entry = htable[i];
            while(entry!=NULL)
            {
                if(entry->zipCode == Zipcode && entry->cast_vote==true)
                {
                    cout<<"Resident Id Number: "<<entry->RIN<<endl;
                    found = true;
                }
                entry = entry->next;
            }
        }
        if(!found)
        {
            cout<<"There is no voters in this zip-code who caste vote"<<endl;
        }
    }

    int countVoter(int zipcode)
    {
        HashNode* entry = NULL;
        int _count = 0;
        for(int i =0; i<TABLE_SIZE; i++)
        {
            entry = htable[i];
            while(entry!= NULL)
            {
                if(entry->zipCode==zipcode && entry->cast_vote==true)
                {
                    _count++;
                }
                entry = entry->next;
            }
        }
        return _count;

    }

    void printZipCode()
    {
        string data[4],str;
        ifstream openfile;
        vector<int> zipcode;
        openfile.open("voters500.csv");
        if(!openfile.is_open())
        {
            cout<<"File is not open"<<endl;
        }
        else
        {
            while(getline(openfile,str))
            {
                int j=0;
                string tmp="";
                int length = str.length();
                for(int i =0; i<(int)str.length(); i++)
                {
                    if(str[i]==' ')
                    {
                        data[j++] = tmp;
                        tmp = "";
                    }
                    else
                    {
                        tmp = tmp + str[i];
                    }

                }
                data[j++] = tmp;
                int zipCode = stoi(data[3]);
                cout<<zipCode<<endl;
                if((registered_voter(zipCode))){
                    zipcode.push_back(zipCode);
                }
            }
            cout<<zipcode.size()<<endl;
            cout<<zipcode.empty()<<endl;
            /*if(!zipcode.empty()){
                sort(zipcode.begin(),zipcode.end());
                for(int i =zipcode.size()-1; i>=0; i--)
                {
                    cout<<zipcode[i]<<endl;
                }
            }
            else{
                cout<<"Empty"<<endl;
            }*/
        }
    }
};

int main()
{
    string choice;
    ifstream fin;
    fin.open("voters500.csv");
    if(!fin.is_open()){
        cout<<"File is not open"<<endl;
    }
    string line;
    while(getline(fin,line)){
        TABLE_SIZE++;
    }
    HashMap _hash;
    while (1)
    {
        cout<<"\n----------------------"<<endl;
        cout<<"Operations on Hash Table"<<endl;
        cout<<"\n----------------------"<<endl;
        cout<<"l. Lookup the hash-table for a voter with \"Resident Id Number\"."<<endl;
        cout<<"i. Insert in the hash-table."<<endl;
        cout<<"d. Delete the voter with \"Resident Id Number\"."<<endl;
        cout<<"r. Registered the voter with \"Resident Id Number\"."<<endl;
        cout<<"bv. Bulk-vote for all the keys."<<endl;
        cout<<"v: Count the voter or Percentage of cast-vote."<<endl;
        cout<<"z: Print the number of all poll participants marked as having votes \"Yes\"."<<endl;
        cout<<"o: Output the number of people who live in each zip-code marked as having votes."<<endl;
        cout<<"exit: Exit the program."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice == "l")
        {
            cout<<"Enter resident id number to be searched: ";
            int residentId;
            cin>>residentId;
            _hash.Search(residentId);
        }

        else if(choice == "i")
        {
            string data[4],str;
            ifstream openfile;
            openfile.open("voters500.csv");
            if(!openfile.is_open())
            {
                cout<<"File is not open"<<endl;
            }
            else
            {
                while(getline(openfile,str))
                {
                    int j=0;
                    string tmp="";
                    int length = str.length();
                    for(int i =0; i<(int)str.length(); i++)
                    {
                        if(str[i]==' ')
                        {
                            data[j++] = tmp;
                            tmp = "";
                        }
                        else
                        {
                            tmp = tmp + str[i];
                        }

                    }
                    data[j++] = tmp;
                    int residentId = stoi(data[0]);
                    int ZipCode = stoi(data[4-1]);
                    _hash.Insert(residentId, data[1],data[2],ZipCode);
                }
            }
            openfile.close();
        }

        else if(choice == "d")
        {
            cout<<"Enter resident id number to be deleted: ";
            int residentId;
            cin>>residentId;
            _hash.Remove(residentId);
        }

        else if(choice == "r")
        {
            cout<<"Enter resident id number to be checked: ";
            int residentId;
            cin>>residentId;
            if(_hash.registered_voter(residentId))
            {
                cout<<"Registration Complted"<<endl;
            }
            else
            {
                cout<<"Already registered or Entry Deleted"<<endl;
            }
        }

        else if(choice == "bv")
        {
            string filename = "voters500.csv";
            _hash.bulk_vote(filename);
        }

        else if(choice == "v")
        {
            cout<<"Cast Vote: "<<_hash.count_voter()<<endl;
            printf("Cast Vote Percentage: %.02f\n",_hash.calculate_percentage());
        }

        else if(choice == "z")
        {
            int zipCode;
            cout<<"Enter the zipcode: ";
            cin>>zipCode;
            _hash.printParticipantId(zipCode);
        }

        else if(choice == "o")
        {
            _hash.printZipCode();
        }

        else if(choice == "exit")
        {
            _hash.~HashMap();
            exit(1);
        }

        else
        {
            cout<<"\nEnter the right key."<<endl;
        }
    }
    return 0;
}
