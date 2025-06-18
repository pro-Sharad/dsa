int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        int suffix = 1;
        int prefix = 1;
        
        int maxProd = INT_MIN;
        
        for(int i = 0; i< n; i++)
        {
            if(suffix == 0)
                suffix = 1;
            if(prefix == 0)
                prefix = 1;
                
            suffix = suffix * arr[i];
            prefix = prefix * arr[n-1-i];
            
            maxProd = max(maxProd, max(suffix, prefix));
        }
        return maxProd;
    }