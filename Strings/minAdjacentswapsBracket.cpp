#include<bits/stdc++.h>
using namespace std;


int swapCount(string s)
{
    int count = 0;
    int p = 0;
    int sum = 0;
    
    //will store the positions of opening brackets
    vector<int> bracketPos;
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '[')
            bracketPos.push_back(i);
    }
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '['){
            count++;
            p++;
        }
        if(s[i] == ']')
            count--;
        
        //imbalace 
        if(count<0)
        {
            //current char position and next '[' position
            sum += bracketPos[p] - i;
            swap(s[i],s[bracketPos[p]]);
            p++;                          //point to next '['
            
            count = 1;    //reset the count
        }
    }
    return sum;
}

int main()
{
    string s = "[]][][";
    cout << swapCount(s) << "\n";

    s = "[[][]]";
    cout << swapCount(s) << "\n";
    return 0;
}