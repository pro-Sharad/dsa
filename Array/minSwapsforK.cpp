int minSwap(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int start = 0, end = n-1;
        int cnt = 0;
        while(start < end)
        {
            if(arr[start] <= k)
                start++;
            else
            {
                if(arr[end] <= k){
                    swap(arr[start++], arr[end--]);
                    cnt++;
                }
                else
                    end--;
            }
        }
        return cnt;
    }