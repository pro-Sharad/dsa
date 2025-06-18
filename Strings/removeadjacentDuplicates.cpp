#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    string s = "";
    
    if(s.empty())
        cout<<"empty string";
    else{
    for(int i=0; i<s.length(); i++)
    {
        char x = s[i];
        if(s[i] == s[i+1] && i+1< s.length()){
        while(x == s[i+1] && i+1 < s.length())
        {
            s[i+1] = ' ';
            i++;
        }
        }
    } 
    }
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    cout<<s;
}
