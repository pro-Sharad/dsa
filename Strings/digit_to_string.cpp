

#include<bits/stdc++.h>
using namespace std;



int main()
{
    string s = "443399902777330968";
    
    string ans = "";
    
    unordered_map<char,string> mappings = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
        {'0', " "}
    };
    
    char lastDigit = '\0';
    int count = 0;
    
    for(char c : s)
    {
        //tracks the last digit(in case when a digit repeats)
        if(c==lastDigit)   
        {
            count++;
        }
        else
        {
            
            if(lastDigit != '\0')  //check for end of string
            {
            if(lastDigit == '0')
                ans+= ' ';
            else
            {
                int index = (count-1)%mappings[lastDigit].size();
                ans += mappings[lastDigit][index];
            }
            }
            
            lastDigit = c;
            count = 1;  //if c doesn't match lastDigit count = 1
        }
    }
    
    //handling the last sequence
    if(lastDigit != '\0')  //check for end of string
            {
            if(lastDigit == '0')
                ans+= ' ';
            else
            {
                int index = (count-1)%mappings[lastDigit].size();
                ans += mappings[lastDigit][index];
            }
            }
    
    cout<<ans;
}