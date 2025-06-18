vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        
        for(int i = 0; i<n; i++)
        {
            int start = arr[i][0];
            int end = arr[i][1];
            
            // if(!ans.empty() && ans.back()[1] >= end)
            //     continue;
            
            for(int j = i+1; j<n; j++)
            {
                if(arr[j][0] <= end){
                    end = max(end, arr[j][1]);
                    i=j;}                       //so that next search starts from next interval             
                else
                    break;
            }
            
            ans.push_back({start, end});
        }
        
        return ans;
    }



//----------------------Second Way--------------------//
vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        
        for(int i = 0; i<n; i++)
    {
        //if it's either the first interval or the next interval after the merge
        if(ans.empty() || arr[i][0] > ans.back()[1])
            ans.push_back(arr[i]);
        //as long as we are doing merge, we just need to update the 2nd index with max value of next interval and the current one    
        else
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
    }
    return ans;
    }
