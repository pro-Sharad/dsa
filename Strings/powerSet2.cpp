
#include <bits/stdc++.h>
using namespace std;

void printSubRec2(string str)
{
    int number_of_subsets = pow(2,str.size());
    for(int counter = 0; counter<number_of_subsets; counter++)
    {
        for(int j=0;j<str.size();j++)
        {
            //checking if that bit is set or not(1 or 0), if 1 print else not
            if((1<<j)&counter)
                cout<<str[j];
        }
        cout<<endl;
    }
}

// Driver program to test above functions
int main()
{
	string str = "abc";
	printSubRec2(str);
	return 0;
}
