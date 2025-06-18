// C++ program to rearrange positive and negative numbers 
// alternately using Two pointers 

#include <bits/stdc++.h>
using namespace std;

// Function to rearrange positive and negative numbers
// in alternate fashion
void rearrange(vector<int>& arr) {
    vector<int> pos, neg;

    // Separate positive and negative numbers
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    int posIdx = 0, negIdx = 0;
    int i = 0;

    // Place positive and negative numbers alternately
    // in the original array
    while (posIdx < pos.size() && negIdx < neg.size()) {
        if (i % 2 == 0)
            arr[i++] = pos[posIdx++];
        else 
            arr[i++] = neg[negIdx++];
    }

    // Append remaining positive numbers (if any)
    while (posIdx < pos.size())
        arr[i++] = pos[posIdx++];

    // Append remaining negative numbers (if any)
    while (negIdx < neg.size())
        arr[i++] = neg[negIdx++];
}

int main() {
    vector<int> arr = {1, 2, 3, -4, -1, 4};
    rearrange(arr);
    for (int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";

    return 0;
}