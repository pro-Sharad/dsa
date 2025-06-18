

#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s = "[()]{}{[())]()}";
    int n = s.size();
    stack<char> st;
    
    if(n%2!=0){
        cout<<"unbalanced";
        return 0;
    }
    
    for(int i=0;i<n;i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            
        //st.empty() for the case when first char we get as ')}]', st will be empty that time     
        if(st.empty() ||
           (s[i] == ')' && st.top() != '(') ||
           (s[i] == '}' && st.top() != '{') ||
           (s[i] == '[' && st.top() != ']') 
        )
        {
            cout<<"unbalanced";
            return 0;
        }
        
        st.pop();
        }
    }
    
    
    if(st.empty())
        cout<<"balanced";
    else
        cout<<"unbalanced";
}