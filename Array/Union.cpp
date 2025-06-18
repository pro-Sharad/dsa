class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        int l1 = a.size();
        int l2 = b.size();
        
        for(int i = 0;i<l2;i++)
            a.push_back(b[i]);
        
        set<int> st;
        
        for(auto x : a){
            st.insert(x);
        }
        
        int ans = st.size();
        return ans;
    }
};