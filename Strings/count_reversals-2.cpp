

#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s = "}{{}}{{{";
    
    int left_count = 0;                //opening count
    int right_count = 0;                //closing count
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '{')
            left_count++;
        else if(left_count == 0)
            right_count++;
        else
            left_count--;      //when right&left matches, we remove left
    }
    
    // Round up for odd counts
    int ans = (left_count + 1) / 2 + (right_count + 1) / 2; 
    cout<<ans;
    return 0;
}