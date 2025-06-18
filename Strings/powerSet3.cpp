//prints all subsets in lexicographical order

#include <bits/stdc++.h>
using namespace std;

// s : Stores input string
// n : Length of s.
// curr : Stores current permutation
// index : Index in current permutation, curr
void printSubSeqRec(string s, int n, int index = -1,
                    string curr = "") {
    // base case
    if (index == n)
        return;

    // Print the current subsequence (including empty)
    cout << curr << "\n";

    // index+1 ensures to print lexicographical order always, as picks next character always
    for (int i = index + 1; i < n; i++) {
        curr += s[i];
        printSubSeqRec(s, n, i, curr);

        // backtracking
        curr = curr.erase(curr.size() - 1);
    }
    return;
}

// Generates power set in lexicographic order.
void printSubSeq(string s) {
    printSubSeqRec(s, s.size());
}

// Driver code
int main() {
    string s = "ab";
    printSubSeq(s);
    return 0;
}