#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string str1 = "onetxofour";
	string str2 = "hellofourtwooneworld";
	
	int n = str1.length();
	int m = str2.length();
	
	if(n>m)
	    cout<<"no";
	
	string sortedstr1 = str1;
	sort(sortedstr1.begin(),sortedstr1.end());
	
	int flag=0;
	for(int i=0;i<m-n;i++)
	{
	    //extract substring of size of smaller string
	    string window = str2.substr(i,n);  
	    sort(window.begin(),window.end());
	    if(sortedstr1 == window){
	        cout<<"yes";
	        flag=1;
	    }
	}
	if(flag==0)
	    cout<<"no";

}
