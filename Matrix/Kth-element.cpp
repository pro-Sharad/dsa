//staircase approach
//it's very useful, it can be used for UpperBound in Matrix
int countSmaller(int mat[MAX][MAX], int n, int mid)
{
    int row = 0, col = n-1;
    int cnt = 0;
    
    while(row < n && col>=0)
    {
        if(mat[row][col] > mid)
            col--;
        //    
        else if(mat[row][col] <= mid)
        {
            cnt += (col+1);         //as col indexing starts from 0
            row += 1;             //as we are standing at last col, to find next greateer number we have to do row++
        }
    }
    return cnt;
}


///Note
/*
Using countSmaller Function:

The function countSmaller(mat, n, mid) returns the number of elements in the matrix that are ≤mid.
If this count is less than k:
It means there are fewer than k elements that are less than or equal to mid. So the kth smallest must be greater than mid. We then set:

low = mid + 1;

If this count is greater than or equal to k:
It means there are at least k elements that are ≤mid. 
Therefore, mid is a candidate for the kth smallest element. We store this candidate in ans 
and try to see if we can find an even smaller candidate (while still having at least k elements less than or equal to it). We then set:
ans = mid;
high = mid - 1;
*/


int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int low = mat[0][0];
  int high = mat[n-1][n-1];
  int ans = 0;
  
  while(low <= high)
  {
      int mid = (low+high)/2;
      int x = countSmaller(mat, n, mid);
      
      if(x < k)
        low = mid+1;
      else{
          ans = mid;
          high = mid-1;
      }        
  }
  return ans;
}



