//----------------USING EXTRA SPACE--------------------------//

#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
	vector<int> vec = {1, 2, 3, 4, 5, 6};
	int n = vec.size();
	vector<int> result = {0};
	
	int i = 0, j = n-1;
	int k = 0;
	
	while(j>i)
	{
	    result[k++] = vec[j];
	    result[k++] = vec[i];
	    i++; j--;
	}
	
	for(int i = 0; i< n; i++)
	    cout<<result[i]<<" ";
	    
	return 0;    
}


///-------------------------WITHOUT EXTRA SPACE------------------------///

void rearrange(vector<int>& arr) {

        // Your code here
        int n = arr.size();
        //important if your array is not sorted
        sort(arr.begin(), arr.end());   
        
        int max_index = n-1;
        int min_index = 0;
        int max = arr[n-1]+1;
        
        for(int i=0;i<n;i++){
            if(i%2==0){
                arr[i] = ( arr[max_index]%max ) * max + arr[i];
                max_index--;
            }else{
                arr[i] = ( arr[min_index]%max ) * max + arr[i];
                min_index++;
            }
        }
        
        for(int i=0;i<n;i++){
            arr[i]/=max; // arr[i] = arr[i]/max;
        }
    }