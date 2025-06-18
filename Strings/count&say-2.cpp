#include <bits/stdc++.h>
using namespace std;

string read(int n)
{
    if(n==1)
        return "1";
    if(n==2)
        return "11";
    
    string str="11";
    
    for(int i=3;i<=n;i++)  //i should start from 3 as 1&2 are already done!
    {
        int cnt=1;
        string temp = "";
        
        for(int j=1;j<str.length();j++)
        {
            if(str[j-1] != str[j])
            {
                temp += to_string(cnt) + str[j-1];
                cnt = 1;
            }
            else
                cnt++;
        }
        
        //add the count of last digit here
        temp += to_string(cnt) + str.back();
        
        str = temp;
    }
    return str;
}

int main() {
	// your code goes here
	string str = read(4);
	cout<<str;
	
	
}
