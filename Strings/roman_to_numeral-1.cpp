

#include<bits/stdc++.h>
using namespace std;



int main()
{
    string s = "MMCMXLIV";
    int res = 0;
    
    unordered_map<char, int> umap = {
    {'I', 1}, {'V', 5}, {'X', 10},
    {'L', 50}, {'C', 100}, {'D', 500},
    {'M', 1000}
    };

    for(int i=0;i<s.length();i++)
    {
        if(i+1<s.length() && umap[s[i+1]] > umap[s[i]]){
            res += umap[s[i+1]] - umap[s[i]];
            i++;
        }
        else
            res += umap[s[i]];
    }
    
    cout<<res;
    return 0;
}




