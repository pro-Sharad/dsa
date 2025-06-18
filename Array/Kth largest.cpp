#include <bits/stdc++.h>
using namespace std;

#---------------------------- O(n*k) --------------------#
int main() {
	// your code goes here
    int arr[8] = {14,9,11,2,3,5,10,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    int k = 5;
    int max = INT_MIN;
    int idx = -1;
    
    for(int j = 0; j<k;j++)
    {
        max = INT_MIN;
        for(int i =0; i<len; i++)
        {
            if(max <= arr[i]){
                max = arr[i];
                idx = i;
            }
        }
        arr[idx] = -1;
    }
    
    cout<<max;
}
#----------------------------------------------------------#


##---------------------QUICKSELECT------------------------------------##
#include <bits/stdc++.h>
using namespace std;

//we are fixing first element as pivot here, all greater numbers will be on left side of it, and vice-versa 
int partition(int arr[], int l, int r)
{
    int pivot = arr[l];
    
    int i = l+1;   //incase only one element is there
    int j = r;
    while(i<j)
    {
        if(arr[i] < pivot && arr[j] > pivot){
            swap(arr[i],arr[j]);
            i++; j--;
        }
        
        if(arr[i] >= pivot)
            i++;
        
        if(arr[j] <= pivot)
        j--;
    }
    swap(arr[j], arr[l]);    // as pivot is in 'l' index
    return j;
}

int Kthlargest(int arr[], int l, int r, int k)
{
    int index = 0;
    
    // If k is smaller than the number of elements
    // in the array.
    if(k > 0 && k <= r - l + 1){
    while(true)
    {
        index = partition(arr, l, r);
        
        if(index == k-1){ 
            break;
        }
        
        //if index >, means we needed 2nd largest, but found 4th largest, so since we have all larger elements on right side of pivot, so right = pivot - 1
        if(index > k-1){  
            r = index-1;
        }
        else{
            l = index +1;
        }
    }
    return arr[index];
    }
    else
    {
        return INT_MAX;
    }
}

int main() {
	// your code goes here
    int arr[8] = {14,9,11,2,3,5,10,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    int k = 3;
    
    if(Kthlargest(arr, 0, len-1, k) == INT_MAX)
        cout<<"k is larger than the number of elements";
    else
        cout<<Kthlargest(arr, 0, len-1, k);

}
##-------------------------------------------------------------------------------##

