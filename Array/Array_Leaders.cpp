vector<int> leaders(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> v;
        v.push_back(arr[n-1]);
        int maxV = arr[n-1];
        
        for(int i = n-2; i >= 0; i--)
        {
            if(arr[i] >= maxV){
                v.push_back(arr[i]);
                maxV = arr[i];
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }