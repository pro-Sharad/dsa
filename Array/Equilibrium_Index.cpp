int findEquilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        int prefixSum = arr[0];
        int suffixSum = 0;
        
        int arrSum = 0;
        for(int i = 0; i< n; i++)
            arrSum += arr[i];
            
        for(int i = 1; i < n; i++)
        {
            suffixSum = arrSum - (arr[i] + prefixSum);
            
            if(suffixSum == prefixSum){
                return i;
            }
            
            prefixSum += arr[i];
        }
        
        return -1;
    }