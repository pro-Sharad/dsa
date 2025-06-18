#include <bits/stdc++.h>
using namespace std;


bool ifvalidShuffle(string str1, string str2, string temp)
{
    unordered_map<char,int> umap;
	if(str1.length()+str2.length() != temp.length())
	{
	    return false;
	}
	else
	{
    	for(int i=0;i<str1.length();i++)
    	{
    	    umap[str1[i]]++;
    	}
    	
    	for(int j=0;j<str2.length();j++)
    	{
    	    umap[str2[j]]++;
    	}
    	
    	for(int k=0;k<temp.length();k++)
    	{
    	    //even if one element doesn't match, return false
    	    if(umap.find(temp[k]) == umap.end()){
    	        return false;
    	    }
    	    else
    	    {
    	        umap[temp[k]]--;
    	        if(umap[temp[k]]==0)
    	            umap.erase(temp[k]);
    	    }
    	}
    	
    	//if map has stil elements left, it means it had extra elements
    	if(umap.size()>0)
    	    return false;
    	else
    	    return true;
	}
}

int main() {
	string str1 = "aryan";
	string str2 = "preeti";
	string temp = "anapreeyrti";
	
	if(ifvalidShuffle(str1,str2,temp))
	    cout<<"yes, it's a valid shuffle";
	else
	    cout<<"no, it's not";
	
	return 0;
}