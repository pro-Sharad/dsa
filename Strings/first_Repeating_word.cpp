#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Ravi had been saying that he ravi ";
    string word = "";
    unordered_map<string,int> umap;

    //for case insensitivity
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    for(int i=0;i<=s.length();i++)  //to include last word within loop
    {
        //the moment i=s.length, means we got our last word, so it will go to else block
        if(i<s.length() && s[i] != ' ') 
        {
            word += s[i];
        }
        else
        {
            //if string ends with trailing spaces, at last we will get empty word to check in else block, so to avoid that
            if(!word.empty()){
            if(umap.find(word) != umap.end())
            {
                cout<<word;
                return 0;
            }
            else
            {
                umap[word]++;
                word = "";
            }
            }
        }
    }
}