#include <bits/stdc++.h>
using namespace std;



//when you pass like this 'int arr[]', means you're passing by reference
int merge(int arr[], int left, int mid, int right)
{
    //initializing cnt var to count inversions
    int cnt = 0;
    
    int n1 = mid-left+1;
    int n2 = right-mid;
    
    //at every merge, there will be 2 arrays left&right, these L & R, will store left & right arrays, which we will merge later
    int L[n1];
    int R[n2];
    
    //k should always start from 'left', not 0, why because, the array whch we are passing is starting from 'left' idx not 0 
    int k = left;                 
    for(int i = 0; i< n1; i++)
        L[i] = arr[k++];
        
    for(int j = 0; j< n2; j++)
        R[j] = arr[k++];   
        
        
    int i = 0, j = 0; 
    k=left;                         
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else{
            //as soon as there is a element in left array > right array, all the elements, right to it, will also be > right array
            // in our case count of all right elements = n1-i 
            cnt += n1 - i;
            arr[k++] = R[j++];
        }
    }
    
    //if any of L or R array is not exhausted yet
    
    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
        
    return cnt;    
}

int mergeSort(int arr[], int left, int right)
{
    int cnt = 0;
    
    //int mid = left + (right-left)/2;
    int mid = (left+right)/2;
    
    //base case
    //when at the leaf node one element is there, stop and return it to merge merge operation will combine it with other leaf nodes and do the sorting
    if(left == right)
        return cnt;
        
    //combining and adding all counts which we get from different sub-arrays    
    cnt += mergeSort(arr, left, mid);
    cnt += mergeSort(arr, mid+1, right);
    cnt += merge(arr, left, mid, right);
    
    return cnt;
}

int main() {
	// your code goes here
    int arr[] = {5,3,2,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<mergeSort(arr, 0, n-1);
    
    // for(int i = 0; i< n; i++)
    //     cout<<arr[i]<<" ";
}
