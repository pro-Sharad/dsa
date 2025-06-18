vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int m = mat.size();     //row count
        int n = mat[0].size();  //column count
        
        int top = 0, right = n-1;
        int bottom = m-1, left = 0;
        
        vector<int> ans;
        
        while(top <= bottom && left <= right)
        {
            //left to right
            for(int j = left; j <= right; j++)
            {
                ans.push_back(mat[top][j]);
            }
            top++;    //as for next iteration top should be increased
            
            ////top to bottom
            for(int i = top; i <= bottom; i++)
            {
                ans.push_back(mat[i][right]);
            }
            right--;
            
            //right to left
            if(top<=bottom){                     //this if condition will make sense, when you have just one horizontal row, or similar conditions
            for(int j = right; j >= left; j--)
            {
                ans.push_back(mat[bottom][j]);
            }
            bottom--;
            }
            
            //bottom to top
            if(left<=right){                  //similarly, this if condition will make sense when you have just one vertical column, 
            for(int i = bottom; i >= top; i--)
            {
                ans.push_back(mat[i][left]);
            }
            left++;
            }
        }
        return ans;
    }