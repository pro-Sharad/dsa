#include <bits/stdc++.h>
using namespace std;

void multiply(vector<int> &arr, int &size, int multiplier)
{
    int carry = 0;
    
    for(int i = 0; i< size; i++)
    {
        int res = arr[i] * multiplier;
        res += carry;
        
        arr[i] = res%10;           //we will store the remainder
        carry = res/10;
    }
    
    //if the carry is 2 or more digits
    while(carry != 0)
    {
        arr[size++] = carry % 10;
        carry = carry/10;
    }
}

int main() {
	int n = 7;
	vector<int> arr(10000, 0);
	int size = 1;
	arr[0] = 1;
	
	vector<int> result;
	
	for(int multiplier = 2; multiplier <= n; multiplier++)
	    multiply(arr, size, multiplier);
	    
	    
	for(int i = size-1; i>= 0; i--)
	    result.push_back(arr[i]);
	    
	for(int i = 0; i< size; i++)
	    cout<<result[i]<<" ";
	  
    return 0;    
}
