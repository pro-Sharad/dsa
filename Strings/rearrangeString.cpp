#include <bits/stdc++.h>
using namespace std;

char countMax(vector<int> count)
{
    char char_max;
    int max_c = INT_MIN;
    for(int i=0;i<count.size();i++)
    {
        if(count[i] > max_c)
        {
            max_c = count[i];
            char_max = i+'a';   //i will hold the indices, 0 for 'a', 1 for 'b', so on.. so i+'a' will return max_char
        }
    }
    return char_max;
}

string rearrange(string s)
{
    int n = s.length();
    vector<int> count(26,0);
    
    for(char ch : s){
        count[ch-'a']++;
    }
    
    char char_max = countMax(count);
    //let say we got char_max as 'd', d(101) - a(97) = 4, at idx 4 in count array we will get maxCount
    int maxCount = count[char_max-'a'];
    
    //check if a character is present more than (n+1)/2
    if(maxCount > (n+1)/2)
        return "";
    
    string res(n,' ');
    int idx = 0;
    
    //first filling even indices
    while(maxCount>0)
    {
        res[idx] = char_max;
        idx = idx+2;
        maxCount--;
    }
    
    count[char_max-'a'] = 0;
    //filling remaining indices, first even then odd
    for(int i=0;i<26;i++)
    {
        while(count[i] != 0){
        idx = idx >= n ? 1 : idx;
        res[idx] = i+'a';
        idx = idx+2;
        count[i]--;
        }
    }
    return res;
}

int main() {
	// your code goes here
	//string s = "aaaaaaaacdbbbbb";
	string s = "aaaaabbbbcc";
	string res = rearrange(s);
	if(res == "")
	    cout<<"not possible";
	else
	    cout<<res;
    return 0;
}
