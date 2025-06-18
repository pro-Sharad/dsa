///----------------------------Finding count of pairs----------------///

#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> arr, int target)
{
    int n = arr.size();
    unordered_map<int, int> umap;
    int cnt = 0;
    
    for(int i = 0; i<n; i++)
    {
        if(umap.find(target-arr[i]) != umap.end())
        {
            cnt += umap[target-arr[i]];
        }
        
        umap[arr[i]]++;
    }
    
    return cnt;
}

int main() {
	// your code goes here
    vector<int> arr = {1, 1, 1, 1}; 
    int target = 2; 
    cout << countPairs(arr, target); 
    
}


///----------------Finding Pairs------------------///
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> countPairs(vector<int> arr, int target)
{
    int n = arr.size();
    unordered_map<int, int> umap;
    vector<pair<int, int>> result;
    
    for(int i = 0; i<n; i++)
    {
        int compliment = target-arr[i];
        if(umap.find(compliment) != umap.end())
        {
            //in case of {1,1,1,1}, this will perfectly make sense
            for(int j = 0; j< umap[compliment]; j++)
            {
                result.push_back({compliment, arr[i]});
            }
        }
        
        //keep updating the frequency of the current element, how many time it occurs
        umap[arr[i]]++;
    }
    
    return result;
}

int main() {
	// your code goes here
    vector<int> arr = {1, 5, 7, -1, 5}; 
    int target = 6; 
    vector<pair<int, int>> ans;
    ans = countPairs(arr, target); 
    
    for(auto x : ans)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
}
