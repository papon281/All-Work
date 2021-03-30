#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>

using namespace std;
class Score
{
public:
    int scoreOfParentheses(string S)
    {
        int ans = 0;
        stack <int> st;
        for(int i = 0; i < S.size(); i+=1)
        {
            if(S[i] == '(')
            {
                st.push(-1);
            }
            else
            {
                if(st.top() == -1)
                {
                    st.pop();
                    st.push(1);
                }
                else
                {
                    int x = 0;
                    while(st.top() != -1)
                    {
                        x=x+st.top();
                        st.pop();
                    }
                    x=x*2;
                    st.pop();
                    st.push(x);
                }
            }
        }
        while(!st.empty())
        {
            ans= ans+st.top();
            st.pop();
        }
        return ans;
    }
};
int main()
{
    string str;
    cin>>str;
    int len = str.length();
    if(len%2==1)
    {
        cout<<0<<endl;
    }
    else
    {
        Score score;
        cout << (score.scoreOfParentheses(str))<<endl;
    }
}
