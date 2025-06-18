int upperBound(vector<int> &arr, int x)
    {
        int n = arr.size();
        int low = 0, high = n-1;
        //in case we can't find any it means it's greater than all elems
        int ans = n;              
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            
            if(arr[mid] > x){
                ans = mid;       //if a[mid]>x, mid could be an ans, so storing it
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
    
    int countSmallerEquals(vector<vector<int>> &mat, int x, int m, int n){
        int cnt = 0;  //gonna hold the count of elems smaller or equal
        
        for(int i = 0; i< m; i++)
        {
            int count = upperBound(mat[i], x);
            cnt += count;
        }
        return cnt;
    }
  
  
    int median(vector<vector<int>> &mat) {
        // code here
        int low = INT_MAX, high = INT_MIN;
        int m = mat.size();     //no of rows
        int n = mat[0].size();   //no of cols
        
        for(int i = 0; i< m; i++)
        {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][n-1]);
        }
        
        int req = (n*m)/2;
        while(low <= high)
        {
            int mid = (low+high)/2;
            
            int smallerEquals = countSmallerEquals(mat, mid, m, n);
            
            if(smallerEquals <= req)
                low = mid+1;
            else
                high = mid-1;
        }
        //since low will contain mid+1, which is what we want
        return low;        
    }