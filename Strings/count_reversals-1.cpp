

#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s = "}{{}}{{{";
    stack<char> st;
    int c1 = 0;                //opening count
    int c2 = 0;                //closing count
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '{')
        {
            st.push('{');
            c1++;
        }
        else if((s[i] == '}') && !st.empty() && (st.top() == '{'))
        {
            st.pop();
            c1--;
        }
        else
        {
            c2++;
        }
    }
    
    //now balanced will be removed, only unbalanced left
    if(c1&1)
        c1 = (c1/2)+1;
    else    
        c1 = c1/2;
    if(c2&1)
        c2 = (c2/2)+1;
    else    
        c2 = c2/2;
    
    cout<<c1+c2;
    return 0;
}