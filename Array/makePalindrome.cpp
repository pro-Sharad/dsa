// C++ program to implement three way partitioning
// around a given range.
#include <bits/stdc++.h>
using namespace std;

int makePalindrome(vector<int> arr)
{
    int n = arr.size();
    int left = 0, right = n-1;
    int merges = 0;
    
    while(left <= right)
    {
        if(arr[left] < arr[right]){
            arr[left+1] = arr[left]+arr[left+1];
            left++;
            merges++;
        }
        else if(arr[left] > arr[right]){
            arr[right-1] = arr[right]+arr[right-1];
            right--;
            merges++;
        }
        else{
            left++;
            right--;
        }
    }
    
    return merges;
}

// Driver code
int main()
{
	vector<int> arr = {11, 14, 14, 11};

	cout<<makePalindrome(arr);
}
