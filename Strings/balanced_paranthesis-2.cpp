

#include<bits/stdc++.h>
using namespace std;


bool checkEqual(char a, char b)
{
    if(a == '(' && b == ')')
        return true;
    if(a == '{' && b == '}')
        return true;
    if(a == '[' && b == ']')
        return true;    
    
    return false;    
}



bool isBalanced(string s,int n)
{
    int top = -1;
    
    for(int i=0;i<n;i++)
    {
        //don't reverse this (s[top],s[i]), as in s[i] we will hold closing brackets
        if(top<0 || !checkEqual(s[top],s[i]))
        {
            top++;
            s[top] = s[i];
        }
        else
            top--;
    }
    
    return top == -1;
} 


int main()
{
    //string s = "[()]{}{[()()]()}";
    string s = "{()}[]";
    int n = s.size();
    if(isBalanced(s,n))
        cout<<"balanced";
    else
        cout<<"unbalanced";
}