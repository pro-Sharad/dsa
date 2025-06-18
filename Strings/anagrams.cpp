#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    string words[] = {"cat", "dog", "tac", "god", "act"};
    unordered_map<string, vector<string>> res;
    
    for(int i=0;i<5;i++)
    {
        string s = words[i];
        sort(s.begin(),s.end());
        res[s].push_back(words[i]);
    }
    
    for(auto x : res)
    {
        for(auto y : x.second)
        {
            cout<<y<<",";
        }
        cout<<endl;
    }
}
