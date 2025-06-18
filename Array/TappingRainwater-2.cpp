#include <bits/stdc++.h>
using namespace std;


void tappingWater(vector<int> arr)
{
    int n = arr.size();
    int res = 0;
    
    int left = 0, right = n-1;
    int leftMax = arr[0];
    int rightMax = arr[n-1];
    
    while(left < right)
    {
        if(arr[left] <= arr[right])
        {
            if(arr[left] >= leftMax)
                leftMax = arr[left];
            else
                res += leftMax - arr[left];
            
            left++;    
        }
        else
        {
            if(arr[right] >= rightMax)
                rightMax = arr[right];
            else
                res += rightMax - arr[right];
            
            right--;    
        }
    }
    
    cout<<res;
}
    
int main() {
	// your code goes here
	vector<int> arr = {2, 1, 5, 3, 1, 0, 4};
    tappingWater(arr);
	
}
