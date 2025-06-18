// C++ program to count swaps required 
// to balance string
#include <bits/stdc++.h>
using namespace std;

int swapCount(string s)
{
    int countLeft = 0, countRight = 0;
    int swaps = 0;
    int imbalance = 0;
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '[')
        {
            countLeft++;
            
            //if there is a imbalance
            if(imbalance > 0)
            {
                swaps += imbalance;
                
                //as it solved one imbalance, so decreasing by 1
                imbalance--;
            }
        }
        else if(s[i] == ']')
        {
            countRight++;
            
            imbalance = countRight - countLeft;
        }
            
    }
    return swaps;
}

// Driver code  
int main()
{
    string s = "[]][][";
    cout << swapCount(s) << endl;

    s = "[[][]]";
    cout << swapCount(s) << endl;

    return 0;
}
