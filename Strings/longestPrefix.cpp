#include <bits/stdc++.h>
using namespace std;

int findMin(int a, int b, int c, int d)
{
    if(a < b && a<c && a<d)
        return a;
    else if(b<c && b<a && b<d)
        return b;
    else if(c<a && c<b && c<d)
        return c;
    else
        return d;
}

int main() {
	string str1 = "geeksforgeeks";
	string str2 = "geeks";
	string str3 = "geek";
	string str4 = "geezer";
    
    int len1 = str1.length();
    int len2 = str2.length();
    int len3 = str3.length();
    int len4 = str4.length();
    
    int shortestLength = findMin(len1, len2, len3, len4);
    
    int cnt = 0;
    
    for(int i=0;i<shortestLength;i++)
    {
        
        if(str1[i] == str2[i] && str2[i] == str3[i] && str3[i] == str4[i]){
            cnt++;
        }
        else
            break;
        
            
    }
    
    if(cnt == 0)
        cout<<"\"\"";
    else
        cout<<str1.substr(0,cnt);
}
