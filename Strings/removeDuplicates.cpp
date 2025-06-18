

#include<bits/stdc++.h>
using namespace std;


//with extra space
int main()
{
    string s = "abaacaacadaeaaf";
    string a="";
    int n = s.size();
    
    for(int i=0;i<n;i++)
    {
        if(a.find(s[i]) == string::npos)
        {
            a+=s[i];
        }
    }
    
    cout<<a;
}

//with using SET
int main() {
    string s = "abaacaacadaeaaf";
    string result = "";
    unordered_set<char> seen;  // Set to track characters that have already appeared

    for (char c : s) {
        if (seen.find(c) == seen.end()) {  // Check if character is not already in the set
            result += c;
            seen.insert(c);  // Add the character to the set
        }
    }

    cout << result;
    return 0;
}

