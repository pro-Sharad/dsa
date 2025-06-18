#include <bits/stdc++.h>
using namespace std;


//when you pass like this 'int arr[]', means you're passing by reference
void merge(int arr[], int left, int mid, int right)
{
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
        else
            arr[k++] = R[j++];
    }
    
    //if any of L or R array is not exhausted yet
    
    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right)
{
    //int mid = left + (right-left)/2;
    int mid = (left+right)/2;
    
    //base case
    //when at the leaf node one element is there, stop and return it to merge merge operation will combine it with other leaf nodes and do the sorting
    if(left == right)
        return;
        
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main() {
	// your code goes here
    int arr[] = {4,1,3,9,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    
    for(int i = 0; i< n; i++)
        cout<<arr[i]<<" ";
}
