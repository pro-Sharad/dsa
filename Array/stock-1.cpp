#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int arr[] = {100, 30, 15, 10, 8, 25, 80};
	int n = 7;
	int profit = 0;
	int maxProfit = INT_MIN;
	
	int minV = arr[0];
	
    for(int i = 0; i< n; i++)
    {
        if(arr[i] < minV)
            minV = arr[i];
        
        profit = arr[i] - minV;
        
        maxProfit = max(profit,maxProfit);
    }
    
    cout<<maxProfit;
}
