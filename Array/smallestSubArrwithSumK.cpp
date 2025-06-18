int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int minCnt = INT_MAX;
        
        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            int sum = 0;
            int j = i;
            while(sum <= x && j< n)
            {
                sum += arr[j++];
                cnt++;
            }
            
            if(sum > x)
                minCnt = min(cnt, minCnt);
        }
        //no sum greater than x
        if(minCnt == INT_MAX)
            return 0;
        
        return minCnt;
    }