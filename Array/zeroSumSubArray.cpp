bool subArrayExists(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        unordered_map<int, int> umap;
        
        int sum = 0;
        
        for(int i = 0; i< n; i++)
        {
            sum += arr[i];
            if(sum == 0 || umap.find(sum) != umap.end()){
                return true;
            }
            
		//there is no need of it, we just store idx values for sake
            umap[sum] = i;
        }
        
        return false;
        
        
    }