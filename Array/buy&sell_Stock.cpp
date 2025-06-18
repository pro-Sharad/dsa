//-----------When multiple transactions allowed-----------------//

int stockBuySell(vector<int> &arr) {
        // code here
        int n = arr.size();
        int profit = 0;
        
        for(int i = 1; i< n; i++)
        {
            if(arr[i] > arr[i-1])
                profit += arr[i]- arr[i-1];
        }
        return profit;
    }


//------------------When only one transaction allowed-------------------//
int main() {
	// your code goes here
    int arr[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int profit = 0;
    int minV = INT_MAX;
    
    for(int i = 0; i< n; i++)
    {
        minV = min(minV, arr[i]);
        profit = max(profit, (arr[i]-minV));
    }
    
    cout<<profit;
}
