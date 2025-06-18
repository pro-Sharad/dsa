#include <bits/stdc++.h>
using namespace std;

string generateWord(string s)
{
    int arr[26] = {0};
    for(char ch : s){
        arr[ch-'a']++;                 //ch-'a', gives the index
    }
    
    string temp = "";
    for(int i = 0;i<26;i++)
    {
        int freq = arr[i];
        if(freq > 0){
            temp += string(freq, i+'a');   //i+'a' gives the char at pos 'i'
        }
    }
    
    return temp;
}

int main() {
	// your code goes here
    string words[] = {"cat", "dog", "tac", "god", "act"};
    unordered_map<string, vector<string>> res;
    
    for(int i=0; i<5;i++)
    {
        string s = words[i];
        
        string new_word = generateWord(s);
        
        res[new_word].push_back(s);
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
