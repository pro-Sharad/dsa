
#include <bits/stdc++.h>
using namespace std;

/*
//Evaluation starts from null string
void printSubRec1(string str, int i, string curr)
{
    if(i==str.length()){
        cout<<curr<<" ";
        return;
    }
    
    printSubRec(str,i+1,curr+str[i]);
    printSubRec(str,i+1,curr);
}*/

//Evaluates from top to bottom meaning from "abc" to a,b,...
void printSubRec2(string str, string curr)
{
    if(str.empty())
    {
        cout<<curr<<" ";
        return;
    }
    
    printSubRec2(str.substr(1),curr+str[0]);
    printSubRec2(str.substr(1),curr);
}

// Driver program to test above functions
int main()
{
	string str = "abc";
	string curr = "";
	//printSubRec1(str,0, curr);
	printSubRec2(str, curr);
	return 0;
}
