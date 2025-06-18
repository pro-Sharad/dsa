int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int m = arr.size();
        int n = arr[0].size();
        
        int maxCnt = INT_MIN, idx = -1;
        
        for(int i = 0; i< m; i++)
        {
            int cnt = -1;
            for(int j = 0; j< n; j++)
            {
                if(arr[i][j] == 1){
                    cnt = n-j;
                    break;
                }
            }
            if(cnt > maxCnt){
                idx = i;
                maxCnt = cnt;
            }
        }
        return idx;
    }