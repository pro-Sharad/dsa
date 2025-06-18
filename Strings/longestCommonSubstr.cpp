#include <bits/stdc++.h>
using namespace std;

int compare(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    
    //i should be <= n-m to avoid checking substring that exceed s1's size
    for(int i = 0; i<= n-m;i++)
    {
        if(s1.substr(i,m) == s2)
            return 1;
    }
    
    return 0;
}

int main()
{
    string str1 = "geeksforgeeks";
    string str2 = "practicewritegeekscourses";
    
    //we can check for the case when one string is empty 
    
    int n = str1.length();
    int m = str2.length();
    int found = 0;
    
    int slen = min(n,m);     //length of smaller substring
    
    for(int i=0;i<slen;i++)
    {
        if(n>=m){
        if(compare(str1, str2.substr(0,slen-i)) == 1)
        {
            cout<<"ans is "<<str2.substr(0,slen-i)<<" of length"<<slen-i;
            found = 1;
            break;
        }
        
        if(compare(str1, str2.substr(i,slen-i)) == 1)
        {
            cout<<"ans is "<<str2.substr(i,slen-i)<<" of length"<<slen-i;
            found = 1;
            break;
        }
        }
        
        else{
        if(compare(str2, str1.substr(0,slen-i)) == 1)
        {
            cout<<"ans is "<<str1.substr(0,slen-i)<<" of length"<<slen-i;
            found = 1;
            break;
        }
        
        if(compare(str2, str1.substr(i,slen-i)) == 1)
        {
            cout<<"ans is "<<str1.substr(i,slen-i)<<" of length"<<slen-i;
            found = 1;
            break;
        }
        }
    }
    
    if(found == 0)
        cout<<"\"\"";
    return 0;
}