
#include <bits/stdc++.h>
using namespace std;

void longestPalSubstr(string str)
{
    int n = str.size();
    if(n<2)
        cout<<str;
        
    int maxLen = 1;
    int start = 0;
    
    for(int i=0;i<n;i++)
    {
        int low = i-1;
        int high = i+1;
        
        while(low>=0 && str[i] == str[low])
            low--;
        
        while(high<n && str[i] == str[high])
            high++;
            
        while(low>=0 && high<n && str[low] == str[high])
        {
            low--; high++;
        }
        
        int length = high-low-1;
        if(length > maxLen)
        {
            maxLen = length;
            start = low+1;
        }
    }
    
    cout<<"longest substring is: "<<str.substr(start,maxLen)<<endl;
    cout<<"length is: "<<maxLen;
}

// Driver program to test above functions
int main()
{
	string str = "forgeeksskeegfor";
	longestPalSubstr(str);
	return 0;
}

TC: O(n^2)
SC: O(1)