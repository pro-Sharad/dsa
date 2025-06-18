#include <bits/stdc++.h>
using namespace std;


// int main()
// {
//     string s = "001";
//     int n = s.length();
    
//     int cnt = 0;
    
//     for(int i=0;i<n;i++)
//     {
//         if(s[i] == '0')
//         {
//             if(s[i] == s[i+1] && i+1<n)
//             {
//                 if(s[i+1] == s[i+2] && i+2<n)
//                 {
//                     s[i+1] = '1';
//                     cnt++;
//                 }
//                 else
//                 {
//                     s[i] = '1';
//                     cnt++;
//                 }
//                 i = i+2;
//             }
//         }
//         else
//         {
//             if(s[i] == s[i+1] && i+1<n)
//             {
//                 if(s[i+1] == s[i+2] && i+2<n)
//                 {
//                     s[i+1] = '0';
//                     cnt++;
//                 }
//                 else
//                 {
//                     s[i] = '0';
//                     cnt++;
//                 }
//                 i = i+2;
//             }
//         }
//     }
    
//     cout<<s<<endl<<cnt;
//     return 0;
// }



int main()
{
    string s = "0001010111";
    int n = s.length();
    
    int cnt = 0; // Count of flips
    
    for (int i = 0; i < n - 1; i++) // Ensure i+1 is within bounds
    {
        if (s[i] == s[i+1]) // If two consecutive characters are the same
        {
            cnt++; // Increment flip count
            
            // Flip the next character to ensure no three consecutive identical characters
            if (i + 2 < n && s[i+1] == s[i+2])
            {
                s[i+1] = (s[i] == '0') ? '1' : '0'; // Flip the middle character
            }
            else
            {
                s[i] = (s[i+1] == '0') ? '1' : '0'; // Flip the current character
            }
            
            // Skip the next character to avoid unnecessary checks
            i = i+2;
        }
    }
    
    cout << s << endl;
    cout << cnt << endl; // Print number of flips
    return 0;
}
