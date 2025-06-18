///----------------------USING SET----------------------------///

int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        set<int> s;
        int cnt = 0;
        int maxCnt = INT_MIN;
        
        for(int i = 0; i< n; i++)
            s.insert(arr[i]);
            
        auto it = s.begin();
        int prev = *it;  // Initialize previous element to the first element
    
        ++it;  // Move to the second element
    
        // Iterate through the set starting from the second element
        for (; it != s.end(); ++it) {
            if(*it - prev == 1)
                cnt++;
            else
                cnt = 0;
                
            maxCnt = max(cnt, maxCnt);    
            prev = *it;  // Update previous to the current element
        }  
        
        return maxCnt+1;
    }



    ///-------------------USING UNORDERED SET-----------------------///
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n = arr.size();
    
    if(n==0)
        return 0;
    
    unordered_set<int> st;
    int longestSum = INT_MIN;
    int cnt = 0;
    
    for(int i = 0; i< n; i++)
        st.insert(arr[i]);
        
    for(auto it : st)
    {
        if(st.find(it-1) == st.end())
        {
            int x = it;
            cnt = 1;
            while(st.find(x+1) != st.end())
            {
                x = x+1;
                cnt++;
            }
        }
        
        longestSum = max(longestSum, cnt);
    }
    return longestSum;
    }