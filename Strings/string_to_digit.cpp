

#include<bits/stdc++.h>
using namespace std;



int main()
{
    string s = "How are you";
    string ans = "";
    
    string str[] = {"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99",
    "999","9999"};
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == ' ')
            ans+= '0';
        else{
            char ch = toupper(s[i]);
            if(ch > 'A' && ch < 'Z')
            {
               int j = ch - 'A';
               ans+= str[j]; 
            }
        }    
    }
    
    cout<<ans;
}