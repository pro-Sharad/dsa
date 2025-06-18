#include<bits/stdc++.h>
using namespace std;

string findMinSubstring(string s, string t)
{
    //if the pattern length is larger return false
    if(t.length() > s.length())
        return "";
        
    int i = 0, j = 0, start = 0;
    int minWindowSize = INT_MAX;    //initialize minWindowSize
    
    unordered_map<char,int> umap;
    for(char ch : t){
        umap[ch]++;
    }
    
    int requiredCount = umap.size();
    
    while(j < s.length())
    {
        //requiredCount will decrease as we have found one element of 't'
        if(umap[s[j]] > 0)
            requiredCount--;
        umap[s[j]]--;
        
        
        //when we found all elements of t, we start shrinking the substring
        while(requiredCount == 0)
        {
            int currWindowSize = j-i+1;
            
            if(minWindowSize > currWindowSize)
            {
                minWindowSize = currWindowSize;
                start = i;
            }
            
            //now, in the next window we will not be including first char of this window, so increasing its count
            umap[s[i]]++;
            
            //now we have excluded one char of 't', so it means we need to find that char in next window, so for that char, we are increasing requiredCount 
            if(umap[s[i]] > 0)
                requiredCount++;
            
            i++;    
        }
        j++;
    }
    
    return minWindowSize == INT_MAX ? "" : s.substr(start,minWindowSize);
}

int main()
{
    string s = "aabcbcdbca";
    string t = "abcd";
    string minSubstring = findMinSubstring(s,t);
    cout<<minSubstring;
    return 0;
}