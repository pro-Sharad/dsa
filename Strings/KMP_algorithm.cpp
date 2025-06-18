#include <bits/stdc++.h>
using namespace std;

vector<int> findLPS(string pattern)
{
    int m = pattern.length();
    vector<int> LPS(m,0);        //initialize and assign
    //int LPS[m];
    int i = 1;
    int length = 0;
    LPS[0] = 0;
    
    while(i<m)
    {
        if(pattern[i] == pattern[length])
        {
            length++;
            LPS[i] = length;
            i++;
        }
        else
        {
            if(length!=0)
            {
                length = LPS[length-1];
            }
            else
            {
                LPS[i] = 0;
                i++;
            }
        }
    }
    
    return LPS;
}


vector<int> KMP(string text, string pattern, vector<int> LPS)
{
    int i = 0;
    int j = 0;
    int n = text.length();
    int m = pattern.length();
    vector<int> res;
    
    while(i < n)
    {
        //this should be checked first, asif checked after matchfoud this will increase i and loop will end and second match will not be found if the match happens at last character
        if(text[i] == pattern[j])   
        {
            i++; j++;
        }
        
        //match found
        if(j==m)
        {
            res.push_back(i-j);
            j = LPS[j-1];
        }
        else if(text[i] != pattern[j] && i<n)
        {
            if(j!=0)
            {
                j = LPS[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    return res;
}

int main() {
	// your code goes here
	
	string text = "geekxgeek";
	string pattern = "geek";

    vector<int> v = findLPS(pattern);
    
    vector<int> result = KMP(text, pattern, v);
    
    for(auto x : result)
    {
        cout<<x<<" ";
    }
}
