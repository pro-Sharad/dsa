#include <bits/stdc++.h>
using namespace std;


void generateBadChar(string s, int BadChar[])
{
    for(int i=0;i<256;i++)
        BadChar[i] = -1;
        
    for(int i=0;i<s.length();i++)
        BadChar[(int)s[i]] = i;
}

void search(string text, string pattern)
{
    int BadChar[256];
    generateBadChar(pattern, BadChar);
    
    int n = text.length();
    int m = pattern.length();
    
    int s = 0;
    
    while(s <= (n-m))
    {
        int j = m-1;
        
        //if char matches keep decreasing j
        while(j>=0 && text[s+j] == pattern[j])
            j--;
            
        //if j =-1, means full pattern matched    
        if(j<0)
        {
            cout<<"match found at "<<s<<" position"<<endl;
            
            //if text[s+m] exist in pattern, the shift aligns the pattern optimally.
            //If txt[s + m] doesn't exist, the pattern is shifted completely past the current position.
            s += (s+m < n) ? m - BadChar[text[s+m]] : 1;
        }
        else
        {
            // The line s += max(1, j - badchar[txt[s + j]]); calculates the next position of the pattern based on the mismatch and ensures a minimum forward shift
            s += max(1, j - BadChar[text[s+j]]);
        }
    }
}

int main() {
	// your code goes here
	
	string text = "AABAACAADAABAABA";
	string pattern = "AABA";

    search(text, pattern);    
}
