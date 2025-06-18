/*
Brute Force
1. generate all permutations in sorted order with recursive approach
2. find the given permutation with linear search
3. then find the next
*/



#include<bits/stdc++.h>
using namespace std;

int main()
{
    int break_point = -1;
    int arr[] = {2,1,5,4,3,0,0};
    
    // Find the break_point (first pair of elements where arr[i-1] < arr[i])
    for (int i = 6; i > 0; i--) {
        if (arr[i - 1] < arr[i]) {
            break_point = i - 1;
            break;
        }
    }

    // If break_point is found, find the right element to swap with
    if (break_point != -1) {
        for (int j = 6; j > break_point; j--) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[break_point + 1]);
                break;
            }
        }
    }
    else{
        reverse(arr,arr+7);
        return;
    }

    // Sort the remaining array after break_point + 1
    //instead of sorting you can also reverse from that index as well
    sort(arr + break_point + 2, arr + 7);  // Sort from break_point + 2 to the end

    // Print the final array
    for (int k = 0; k < 7; k++) {
        cout << arr[k] << " ";
    }

    return 0;
}
