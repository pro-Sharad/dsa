int findMax(vector<int> arr, int n)
    {
        int maxV = INT_MIN;
        int maxIdx = -1;
        for(int i = 0; i< n; i++)
        {
            if(arr[i] > maxV)
            {
                maxV = arr[i];
                maxIdx = i;
            }
        }
        return maxIdx;
    }
    
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
    int maxIdx = -1;
    int res = 0;
    
    maxIdx = findMax(arr, n);
    
    if(maxIdx == 0)
    {
        //cout<<"if me aaya hai"<<endl;
        int last = arr[n-1];
        int sum = 0;
        for(int i = n-2; i > 0; i--)
        {
            if(arr[i] >= last)
            {
                sum = 0;
                last = arr[i];
            }
            else{
                sum = last - arr[i];
                res += sum;
            }
        }
    }
    
    else if(maxIdx == n-1)
    {
        //cout<<"elseIf aaya hai"<<endl;
        int first = arr[0];
        int sum = 0;
        for(int i = 1; i < maxIdx; i++)
        {
            if(arr[i] >= first)
            {
                sum = 0;
                first = arr[i];
            }
            else{
                sum = first - arr[i];
                res += sum;
            }
        }
    }
    
    else
    {
        //cout<<"else me aaaya"<<endl;
        int first = arr[0];
        int last = arr[n-1];
        int sum = 0;
        for(int i = 1; i < maxIdx; i++)
        {
            if(arr[i] >= first)
            {
                sum = 0;
                first = arr[i];
            }
            else{
                sum = first - arr[i];
                res += sum;
            }
        }
        
        sum = 0;
        for(int i = n-2; i > maxIdx; i--)
        {
            if(arr[i] >= last)
            {
                sum = 0;
                last = arr[i];
            }
            else{
                sum = last - arr[i];
                res += sum;
            }
        }
    }
    
    return res;
    }