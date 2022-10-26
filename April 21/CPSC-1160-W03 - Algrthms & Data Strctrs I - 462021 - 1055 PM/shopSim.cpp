#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>>
#include "queue.h"

using namespace std;
int main()
{

    vector<string> data;
    vector<int> arrivals;
    vector<int> serve;
    vector<double> pay;

    cout << "Enter the number of cashier: ";
    int n;
    cin >> n;
    cout << "Enter the filename: ";
    string filename;
    cin >> filename;

    //Declare the object of number of cashier
    queue<int> q[n];
    vector<int> mx(n), cnt(n);
    vector<double> cost(n);

    //Initialize the max,count and cost vector
    for(int i = 0; i < n; i++)
    {
        cost[i] = 0;
        mx[i] = 0;
        cnt[i] = 0;
    }


    ifstream fin;
    fin.open(filename);

    if(!fin.is_open())
    {
        cout <<"File is not open" << endl;
        exit(0);
    }
    int arrival;

    //Read the customer arrival time from file
    while(fin >> arrival)
    {
        int service;
        //read the service time from file
        fin >> service;
        //Read the payment from file
        double p;
        fin >> p;
        //Store the data in the vector
        arrivals.push_back(arrival);
        serve.push_back(service);
        pay.push_back(p);
    }

    //Loop for calculate the cost and Total time
    for(int i = 0; i < arrivals.size(); i++)
    {

        int mnQ = -1;
        int mnQSize = 999999999;

        for(int j = 0; j < n; j++)
        {
            // Check the current queue size
            //If current queue is not empty and
            //Current time is less or equal current arrival time
            //Dequeue the current queue
            while(!q[j].isEmpty() && q[j].front() <= arrivals[i])
            {
                q[j].dequeue();
            }

            //Compare the minimum size with current queue
            //Update the minimum size
            //Update the minimum queue
            if(q[j].getSize() < mnQSize)
            {
                mnQSize = q[j].getSize();
                mnQ = j;
            }
        }

        //Update the max time in the mx array
        //compare with current max and current arrival time
        //And add the current service time
        mx[mnQ] = max(mx[mnQ], arrivals[i]) + serve[i];

        //Enqueue the minimum queue
        q[mnQ].enqueue(mx[mnQ]);

        //Update the cost of current cashier earned
        cost[mnQ] += pay[i];
        //Count the service provide by current cashier
        cnt[mnQ]++;
    }

    int totalTime = 0;

    //Store the total time
    for(int i = 0; i < n; i++)
    {
        totalTime = max(totalTime, mx[i]);
    }

    cout<<"total time: "<< totalTime <<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<"cashier "<<i<<" helped "<<cnt[i]<<" customers and took in $"<<cost[i]<<endl;
    }
    return 0;
}
