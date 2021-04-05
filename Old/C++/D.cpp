#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main()
{
    int n,capacity,overflow=0,underflow=0;
    stack<int> st;
    string parenthesis;
    cin>>n;
    cin>>parenthesis;
    cin>>capacity;
    for(int i=0; i<n; i++)
    {
        if(parenthesis[i]=='(')
        {
            st.push(i);
            if(st.size() > capacity){
                overflow = i;
                break;
            }
        } else {

            if(!st.empty())
            {
                st.pop();
            }
        }
    }
    if(st.size() == 0){
        overflow = n-1;
    }
    while(!st.empty()){
        st.pop();
    }

    for(int i=n-2; i>=0; i--)
    {
        if(parenthesis[i]==')')
        {
            st.push(i);
        }
        else{
            if(!st.empty())
            {
                st.pop();
            }
            else
            {
                    underflow=i;
                    break;
            }
        }

    }
    int ans=overflow-underflow;
    if(ans<0){
        cout<<0<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    return 0;
}

