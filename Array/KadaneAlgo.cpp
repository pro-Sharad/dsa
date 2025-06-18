#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
	vector<int> arr= {
    -7041, -2643, -3502, 8141, 3769, -6551, 8520, -8534, 292, 6533, 
    -7707, -7824, -3779, 3389, -6951, 185, 5636, -6085, 1051, -4740, -8599
    };

    int sum = 0;
    int maxSum = INT_MIN;
    int negativeCnt = 0;
    
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0)
            negativeCnt++;
    }
    
    if(negativeCnt == arr.size())
        maxSum = *max_element(arr.begin(), arr.end());
    else{
    for(int i=0;i<arr.size();i++)
    {
        if(sum+arr[i] < 0)
            sum = 0;
        else
            sum += arr[i];
            
        
        if(sum > maxSum)
        {
            maxSum =sum;
            
        }
    }
    cout<<maxSum;
    }
    //return maxSum;
}
