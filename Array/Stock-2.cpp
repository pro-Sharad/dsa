#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int arr[] = {10, 22, 5, 75, 65, 80};
	int n = 6;
	int profit = 0;
	
    for(int i = 0; i< n-1; i++)
    {
        if(arr[i] < arr[i+1])
            profit += arr[i+1] - arr[i];
    }
    
    cout<<profit;
}
