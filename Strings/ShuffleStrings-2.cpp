#include <bits/stdc++.h>
using namespace std;


bool ifvalidShuffle(string str1, string str2, string temp)
{
	if(str1.length()+str2.length() != temp.length())
	{
	    return false;
	}
	
	int k=0, i=0, j=0;
	while(k<temp.length())
	{
	    if(i<str1.length() && str1[i] == temp[k])
	        i++;
	    else if(j<str2.length() && str2[j] == temp[k]) 
	        j++;
	    else
	        return false;
	    k++;     
	}
	
	//this will return false if both strings are not fully traversed yet
	return (i==str1.length()) && (j==str2.length());
}

int main() {
	string str1 = "abc";
	string str2 = "def";
	string temp = "adbcef";
	
	if(ifvalidShuffle(str1,str2,temp))
	    cout<<"yes, it's a valid shuffle";
	else
	    cout<<"no, it's not";
	
	return 0;
}