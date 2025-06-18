#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool WordBreak(string s, const vector<string> d)
{
    //this is the base case when whole string is exhausted,means it was valid
    if(s.empty())
        return true;
        
    int n = s.length();
    
    
    //if the prefix of length i is a dictionary word and rest of the string can also be broken into valid words, return true
    
    for(int i=1;i<=n;i++) //from 1 till n, as it will denote 'length of the string' so 1 till n
    {
        string prefix = s.substr(0,i);
        
        //check if this prefix as well as the remaining substring is present in dictionary
        if(find(d.begin(),d.end(),prefix) != d.end() && 
        WordBreak(s.substr(i), d))
        {
            return true;
        }
    }
    
    //if none of the above condition returns true, then it's not valid
    return false;
}


int main()
{
    vector<string> d = { "mobile", "samsung",  "sam",  "sung", "man",
                         "mango",  "icecream", "and",  "go",   "i",
                         "like",   "ice",      "cream" };
    
    cout << (WordBreak("ilikesamsung", d) ? "Yes\n" : "No\n");
    cout << (WordBreak("iiiiiiii", d) ? "Yes\n" : "No\n");
    cout << (WordBreak("", d) ? "Yes\n" : "No\n");
    cout << (WordBreak("gomob", d) ? "Yes\n" : "No\n");
    cout << (WordBreak("samsungandmango", d) ? "Yes\n" : "No\n");
    cout << (WordBreak("samsungandmangok", d) ? "Yes\n" : "No\n");

    return 0;
}