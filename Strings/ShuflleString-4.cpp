#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string str1 = "onetwofour";
	string str2 = "hellofourtwooneworld";
	
	int n = str1.length();
	int m = str2.length();
	int flag=0;
	
	if(n>m)
	    cout<<"no";
	
	unordered_map<char,int> umap1;  //for storing string 1 frequency
	unordered_map<char,int> umap2;  //for storing window
	
	for(char c : str1){
	    umap1[c]++;
	}
	
	for(int i=0;i<m;i++)
	{
	    umap2[str2[i]]++;
	    
	    if(i>=n)
	    {
	        //keep removing last char to maintain window len equal to str1
	        char charToRemove = str2[i-n];
	        umap2[charToRemove]--;
	        
	        if(umap2[charToRemove]==0)
	            umap2.erase(charToRemove);
	    }
	    
	    //if window and str1 matches at some point return true
	    if(umap1 == umap2){
	        cout<<"yes";
	        flag=1;
	    }
	}
	if(flag==0)
	    cout<<"no";
}
