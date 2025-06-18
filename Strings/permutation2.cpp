

#include<bits/stdc++.h>
using namespace std;

void permute(string s, int idx,int n)
{
    if(idx==n)
    {
        cout<<s<<endl;
        return;
    }
    
    for(int i=idx;i<n;i++)
    {
        swap(s[i],s[idx]);
        permute(s,idx+1,n);
        swap(s[i],s[idx]);
    }
}

int main()
{
    string s = "ab";
    int n = s.size();
    permute(s,0,n);
}
