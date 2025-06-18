void threeWayPartition(vector<int>& arr, int a, int b) {
        // code here
        int n = arr.size();
        int start = 0, end = n-1;
        
        //here we are moving till, end because for eg if arr[5], 
        //which is last index is swapped, we don't want to be checked
        //again, which we will if we move till n-1
        //simply we don't want to check those which are already processed
        for(int i = 0; i <= end;)
        {
            if(arr[i] < a)
            {
                if(i==start)
                {
                    i++;
                    start++;
                }
                //if we don't add else here, for start=0, i=0, it will do start = 1, i = 1, because of above if block
                // and swap(a[1], a[1]), which should not be the case
                // we need to check if a[1] < a or a[i] > b
                // that's why we have added swap only in else block, 
                else
                    swap(arr[i++], arr[start++]);
            }
            else if(arr[i] > b)
            {
                //here we are not incrementing i, because after swapping 
                //we might get another a[i] > b
                swap(arr[end--], arr[i]);
            }
            else
                i++;
        }
    }