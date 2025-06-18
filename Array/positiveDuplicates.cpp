//for +ve & -ve, use Hashmap, it will also take O(n)

vector<int> findDuplicates(vector<int>& arr) {
        // code here
        auto maxElementIt = max_element(arr.begin(), arr.end());
    	int len = arr.size();
    	
    	vector<int> result;
    	
    	vector<int> freq(*maxElementIt+1,0);
    	
    	int len2 = *maxElementIt+1;
    	for(int i=0;i<len;i++)
    	{
    	    freq[arr[i]]++;
    	}
    	for(int j=0;j<len2; j++)
    	{
    	    if(freq[j] > 1)
    	        result.push_back(j);
    	   //cout<<freq[j]<<" ";
    	}
    	
    	return result;
    }