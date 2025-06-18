#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    string str  = "forgeeksskeegfor";
    string temp = "";
    string temp2 = "";
    string result = "";
    int maxLen = -1;
    int flag = 0;
    
    for(int i=0;i<str.length();i++)
    {
        for(int j=str.length();j>i;j--)
        {
            temp = str.substr(i,j-i);
            temp2 = temp;
            reverse(temp2.begin(),temp2.end());
             
            if(temp == temp2)
            {
                if(int(temp.length()) > maxLen)
                {
                    result = temp;
                    maxLen = int(temp.length());
                }
            }
        }
    }
    //print final string
    cout<<result;
}

TC : O(N^3)
SC : O(N)