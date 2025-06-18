#include<bits/stdc++.h>
using namespace std;

string findMinSubstring(string s)
{
    set<char> st;
    for(char ch : s){
        st.insert(ch);
    }
    int dist_count = st.size();
    
    int start = 0, start_index = -1, count =0, minWindowlen = INT_MAX;
    
    //this will store ASCII values of each character and their count 
    int curr_count[256] = {0};    
    for(int j=0;j<s.length();j++)
    {
        curr_count[s[j]]++;
        
        //increase count only if char comes first time, 
        if(curr_count[s[j]] == 1)
            count++;
        
        //when a window found
        if(count == dist_count)
        {
            //shrink the window by removing chars which are present more than once
            while(curr_count[s[start]] > 1)
            {
                if(curr_count[s[start]] > 1)
                    curr_count[s[start]]--;
                start++;    
            }
            
            //finding for min len window
            int currWindowlen = j-start+1;
            if(minWindowlen > currWindowlen)
            {
                minWindowlen = currWindowlen;
                start_index = start;
            }
        }
        
        
    }
    return s.substr(start_index,minWindowlen);
}

int main()
{
    string s = "aabcbcdbca";
    string res = findMinSubstring(s);
    cout<<res;
    return 0;
}