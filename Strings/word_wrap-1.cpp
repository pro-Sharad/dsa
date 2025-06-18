

#include<bits/stdc++.h>
using namespace std;

int findWrap(int curr, int spaces, vector<int> nums, int k)
{
    if(curr == nums.size())
        return 0;
        
    //continue in the same line
    int newSpaces = spaces + 1 + nums[curr];
    
    int a = INT_MAX;
    if(newSpaces <= k)
    {
        a = findWrap(curr+1, newSpaces, nums, k);
    }
    
    //nextLine
    int b = findWrap(curr+1, nums[curr], nums, k) + (k-spaces)*(k-spaces);
    
    return min(a,b);
}

int main()
{
    vector<int> nums = {3, 2, 2, 5};
    int k = 6;
    cout<<findWrap(1, nums[0], nums, k);
    return 0;
}




