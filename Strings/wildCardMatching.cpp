#include <bits/stdc++.h>
using namespace std;

void wildcardMatching(string s1, string s2)
{
    int j = 0, i=0;
    while(i<s2.length())
    {
        if(s1[j] == '\0' && s2[i] == '\0'){
            cout<<"matched";
            return; 
        }
        // If one string ends but the other doesn't, it's not matched
        if (s1[j] == '\0' || s2[i] == '\0') {
            cout << "not matched";
            return;
        }
        
        else if(s1[j] != '*' && s1[j] != '?' && s1[j] != s2[i]){
            cout<<"not matched";
            return;
        }
        
        if(s1[j] == '?' || s1[j] == s2[i]){
            j++; i++;
        }    
        else if(s1[j] == '*')
        {
            if(s1[j+1] == '\0'){
                cout<<"matched";
                return;
            }
            else{
                while(i < s2.length() && s2[i] != s1[j + 1])
                    i++;
                //this will also work, when * matches 0 chars like 'globe' & 'glo*be' 
                if (i < s2.length() && s2[i] == s1[j + 1]) {
                    j++;
                } 
                else {
                    // No match found for the character after '*' in s1, return false
                    cout << "not matched";
                    return;
            }
                
            }    
            
        }
    }
    
    // Handle the case where s1 has only '*' remaining after the loop
    // We need to ensure all remaining characters of s1 are '*' to consider it matched
    while (s1[j] == '*') {
        j++;
    }
    
    //while loop is limited to s2 length only, so while checking for a *, let say it gets exhausted, then we need to explicitly check if s1 ends or not
    if(s1[j] == '\0')
        cout<<"matched";
    else
        cout<<"not matched";
}

int main() {
	// your code goes here
    string s1= "g*k";
    string s2 = "gee";
    wildcardMatching(s1,s2);
}
