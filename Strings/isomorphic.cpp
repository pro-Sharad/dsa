#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    string s1 = "crtdo";
    string s2 = "telgb";
    
    int j = 0, flag = 1;
    unordered_map<char, char> umap;
    for(int i = 0; i< s1.length();i++)
    {
        if(umap.find(s1[i]) == umap.end())
        {
            umap[s1[i]] = s2[j];
            j++;
        }
        else{
            if(umap[s1[i]] != s2[j]){
                cout<<"not isomorphic";
                flag = 0;
                break;
            }
        }
    }
    
    //reverse checking
    umap.clear();          //removing all elements from map
    j = 0;
    for(int i = 0; i< s2.length();i++)
    {
        if(umap.find(s2[i]) == umap.end())
        {
            umap[s2[i]] = s1[j];
            j++;
        }
        else{
            if(umap[s2[i]] != s1[j]){
                cout<<"not isomorphic";
                flag = 0;
                break;
            }
        }
    }
    
    if(flag == 1){
        cout<<"isomorphic";
    }
    // for(auto x : umap){
    //     cout<<x.first<<":"; 
    //     for(auto i : x.second)
    //         cout<<i<<" ";
    //     cout<<endl;    
    // }
}
