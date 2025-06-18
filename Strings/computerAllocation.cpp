#include <bits/stdc++.h>
using namespace std;

int runCustomerSimulation(int computerCount, string s)
{
    int customerCount = 0;
    set<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(st.find(s[i]) != st.end()){
            computerCount++;
        }
        else{
            st.insert(s[i]);
            computerCount--;
            
            if(computerCount<0)
            customerCount++;
        }
        
    }
    return customerCount;
}

int main() {
	// your code goes here
    cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl; 
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl; 
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl; 
    cout << runCustomerSimulation(1, "ABCBCA") << endl; 
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl; 
    return 0; 
}



