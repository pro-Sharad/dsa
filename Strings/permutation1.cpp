#include <bits/stdc++.h>
using namespace std;

void printPermutations(string s, int n, vector<string> ds, int freq[], vector<vector<string>> &ans)
{
    if(ds.size() == n)
    {
        ans.push_back(ds);
        return;
    }
    
    for(int i=0;i<n;i++)
    {
        if(freq[i]==0)
        {
            freq[i] = 1;
            ds.push_back(string(1, s[i]));
            printPermutations(s, n, ds, freq,ans);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

// Driver code
int main() {
    string s = "abc";
    int n = s.length();
    std::vector<string> ds;
    vector<vector<string>> ans;
    int freq[n];
    for(int i=0;i<n;i++){ freq[i] = 0; }
    printPermutations(s, n, ds, freq, ans);
    
    for (const auto& outer : ans) {
        for (const auto& str : outer) {
            cout << str;  // Print each string in the inner vector
        }
        cout << endl;  // Newline after each inner vector (i.e., after each permutation)
    }
    
    return 0;
}