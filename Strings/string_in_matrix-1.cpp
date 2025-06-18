

#include<bits/stdc++.h>
using namespace std;


int solve(string s, char ch[][6], int i, int j, int n, int idx)
{
    int found = 0;
    
    
    if(i>=0 && j>=0 && i<6 && j<6 && ch[i][j] == s[idx])
    {
        char temp = ch[i][j];
        ch[i][j] = 0;
        
        if(idx == n)
            found=1;
        else{
        found+=solve(s,ch,i+1,j,n,idx+1);
        found+=solve(s,ch,i-1,j,n,idx+1);
        found+=solve(s,ch,i,j+1,n,idx+1);
        found+=solve(s,ch,i,j-1,n,idx+1);
        }
        
        ch[i][j] = temp;
    }
    return found;
}

int main()
{
    string s = "GEEKS";
    char ch[6][6] ={
            {'D','D','D','G','D','D'},
            {'B','B','D','E','B','S'},
            {'B','S','K','E','B','K'},
            {'D','D','D','D','D','E'},
            {'D','D','D','D','D','E'},
            {'D','D','D','D','D','G'}
          };
    
    int ans = 0;
    int n = s.size();
    
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            ans += solve(s,ch,i,j,n,0);
        }
    }
    
    cout<<ans;
    return 0;
}




