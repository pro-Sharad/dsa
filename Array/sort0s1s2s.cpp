#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
    int arr[] = {0, 1, 2,0,1,2};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    int freq[3] = {0};
    
    for(int i = 0; i<len; i++)
    {
        freq[arr[i]]++;
    }

    int i = 0;
    for(int num = 0; num<=2; num++)
    {
        while(freq[num]--){
            arr[i] = num;
            i++;
        }
    }
    
    for(int i = 0; i<len; i++)
    {
        cout<<arr[i]<<" ";
    }
}
