#include<bits/stdc++.h>
using namespace std;

vector<int> computeLPSArray(string &pat) {
    int n = pat.length();
    vector<int> lps(n);

    // lps[0] is always 0
    lps[0] = 0;
    int len = 0;

    // loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < n) {

        // If the characters match, increment len
        // and set lps[i]
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }

        // If there is a mismatch
        else if (pat[i] != pat[len]) {

            // If len is not zero, update len to
            // the last known prefix length
            if (len != 0) {
                len = lps[len - 1];
            }

            // No prefix matches, set lps[i] to 0
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}


int main() {
    string s = "dmtjtvqyiedezraoqkfu";
    string s2 = s;
    
    reverse(s2.begin(),s2.end());
    
    string temp = s + '$' + s2;
    vector<int> lps = computeLPSArray(temp);
    
    cout<<s.length() - lps.back();
    return 0;
}