

#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s = "0100011101001101";
    
    int start_idx = 0;
    int zero_count = 0;
    int one_count = 0;
    string ans = "";
    
    for(int i=0;i<s.size();i++)
    {
        if(zero_count == one_count && zero_count!=0 && one_count!=0)
        {
            ans = s.substr(start_idx,zero_count+one_count);
            cout<<ans<<endl;
            start_idx = i;
            zero_count = one_count = 0;
        }
        
        if(s[i] == '0')
        {
            zero_count++;
        }
        else
        {
            one_count++;
        }
        ans = "";
    }
    
    //the last remaining substring
    if(zero_count == one_count && zero_count!=0 && one_count!=0)
    {
        ans = s.substr(start_idx,zero_count+one_count);
        cout<<ans<<endl;
    }
    return 0;
}