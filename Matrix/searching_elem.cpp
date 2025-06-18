bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int m = mat.size();      //no of rows
        int n = mat[0].size();   //no of columns
        
        int i = 0, j = n-1;
        
        while(i < m && j >= 0)
        {
            if(x == mat[i][j])
                return true;
            //if it's greater than last elem of row, search in next row 
            else if(x > mat[i][j]) 
                i++;
            else                //if it's lesse than last elem of row, search in that row
                j--;
        }
        return false;
    }