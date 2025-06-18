int findMinDiff(vector<int>& a, int m) {
        // code here
        int n = a.size();
        sort(a.begin(), a.end());
        
        int minDiff = INT_MAX;
        int diff = 0;
        
        for(int i = 0; i <= n-m; i++)
        {
            int minV = a[i];
            int maxV = a[i+m-1];
            
            diff = maxV-minV;
            minDiff = min(minDiff, diff);
        }
        return minDiff;
    }