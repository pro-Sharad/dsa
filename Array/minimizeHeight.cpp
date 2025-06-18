#include <bits/stdc++.h>
using namespace std;

int minDiff(vector<int> arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int res = arr[n-1] - arr[0];
    
    for(int i=1;i<n;i++)
    {
        //if this is the case, continue with next tower/height
        if(arr[i]-k < 0)
            continue;
        
        int minH = min(arr[0]+k, arr[i]-k);
        int maxH = max(arr[i-1]+k, arr[n-1]-k);
        
        res = min(res, maxH - minH);
    }
    
    return res;
}

int main() {
	// your code goes here
	vector<int> arr= {12, 6, 4, 15, 17, 10};
	int k = 6;
	
	cout<<minDiff(arr, k);
}
