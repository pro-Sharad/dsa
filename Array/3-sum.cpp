bool hasTripletSum(vector<int> &arr, int target) {
        // Your Code Here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i< n; i++)
        {
            int k = n-1;
            int j = i+1;
            while(j< n && k>i)
            {
                if(arr[i] + arr[j] + arr[k] == target && k > j){
                    return true;
                }
                else if(arr[i] + arr[j] + arr[k] > target)  
                    k--;
                else
                    j++;
            }
        }
        return false;
    }