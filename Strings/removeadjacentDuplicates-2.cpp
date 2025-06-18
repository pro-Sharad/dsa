#include <bits/stdc++.h>
using namespace std;

void removeConsecutive(char *s)
{
    //if string is empty return 
    if(s[0] == '\0')
        return;
    
    if(s[0] == s[1])
    {
        int i = 0;
        //if 2 chars match shift the whole string to the left
        while(s[i] != '\0')
        {
            s[i] = s[i+1];
            i++;
        }
        //after shifting, pass the string once again to check if there are any more duplicates, in case of 'aaaa', this wll be called 3 times
        removeConsecutive(s);
    }
    //if first 2 consecutive chars don't match, move to the next one
    removeConsecutive(s+1);
}

int main() {
	// your code goes here
    char s[] = "aaaabbbbccc";
    removeConsecutive(s);
    cout<<s;
}
