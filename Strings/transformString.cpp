#include <bits/stdc++.h>
using namespace std;

int transform(string s1, string s2)
{
    if(s1.length() != s2.length())
        return -1;
    
    //here we are checking if both the characters, has same chars 
    int count[256] = {0};
    for(int i=0;i<s1.length();i++)
        count[s1[i]]++;
    for(int j=0;j<s2.length();j++)
        count[s2[j]]--;
    //if one character mismatches we return -1    
    for(int k=0;k<256;k++){
        if(count[k])
            return -1;
    }    
    
    //algo starts mere bhai
    int i = s1.length()-1;
    int j = s2.length()-1;
    int cnt = 0;
    
    //we start traversing from the end, unless one gets exhausted
    while(i>=0 && j>=0)
    {
        //whenever a mismatch occurs, we decrease i only, as we are still finding a match for j, and increment cnt, as the idea is the number of mismatches we find is equal to the number of chars we need to add to front
        while(i>=0 && s1[i] != s2[j])
        {
            cnt++;
            i--;
        }
        i--; j--;
    }
    return cnt;
}

int main() {
	// your code goes here
	string s1 = "ABD";
	string s2 = "ADB";
	cout<<transform(s1,s2);
    return 0; 
}



