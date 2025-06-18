#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    if(s.empty() || s.length() > 3)
        return false;
    if(s[0] == '0' && s.length() >1)
        return false;
    int a = stoi(s);
    return a>=0 && a<=255;
}

void generateIP(string s, int idx, int level, string curr,int n,vector<string> &ans)
{
 
    if(n>12)
        return;
        
    if(idx == n && level == 4)
    {
        curr.pop_back();
        ans.push_back(curr);
    }
    else if(level >= 4)
        return;
    
    else
    {
        if(idx+1 <=n && isValid(s.substr(idx,1)))
            generateIP(s,idx+1,level+1,curr+s.substr(idx,1)+'.',n,ans);
        
        if(idx+2 <=n && isValid(s.substr(idx,2)))
            generateIP(s,idx+2,level+1,curr+s.substr(idx,2)+'.',n,ans);
        
        if(idx+3 <=n && isValid(s.substr(idx,3)))
            generateIP(s,idx+3,level+1,curr+s.substr(idx,3)+'.',n,ans);
    }
}

int main() {
	// your code goes here
	string str1 = "25525511135";
	int n1 = str1.length();
	
	
	vector<string> ans;
    generateIP(str1,0,0,"",n1,ans);
    
    for (auto s : ans) {
        cout << s<<endl;
    }
    
}
