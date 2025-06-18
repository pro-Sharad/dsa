#include <bits/stdc++.h>
using namespace std;

string read(int n)
{
    if(n==1)
        return "1";
    
        int cnt=1;
        string str = read(n-1);
        string str2 = "";
        
        for(int i=0;i<str.length();i++)
        {
            if(i+1<str.length() && str[i]==str[i+1])
            {
                cnt++;
            }    
            
            else
            {
                str2+= to_string(cnt) + str[i];
                cnt=1;
            }
        }
        return str2;
    
}

int main() {
	// your code goes here
	string str = read(5);
	cout<<str;
	
	
}
