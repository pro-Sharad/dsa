#include<bits/stdc++.h>
using namespace std;

int solve(string s, char ch[][6], int i, int j, int n, int idx, int dirX, int dirY)
{
    int found = 0;

    // Check boundaries and current character
    if (i >= 0 && j >= 0 && i < 6 && j < 6 && ch[i][j] == s[idx])
    {
        char temp = ch[i][j]; // Save the current character
        ch[i][j] = 0;         // Mark the cell as visited

        if (idx == n - 1)     // If the full string is found
            found = 1;
        else {
            if (dirX == 0 && dirY == 0) { // If no direction chosen, explore all straight directions
                found += solve(s, ch, i + 1, j, n, idx + 1, 1, 0); // Down
                found += solve(s, ch, i - 1, j, n, idx + 1, -1, 0); // Up
                found += solve(s, ch, i, j + 1, n, idx + 1, 0, 1); // Right
                found += solve(s, ch, i, j - 1, n, idx + 1, 0, -1); // Left
            } else { // Continue in the same direction
                found += solve(s, ch, i + dirX, j + dirY, n, idx + 1, dirX, dirY);
            }
        }

        ch[i][j] = temp; // Restore the cell
    }
    return found;
}

int main()
{
    string s = "GEEKS";
    char ch[6][6] = {
        {'D', 'D', 'D', 'G', 'D', 'D'},
        {'B', 'B', 'D', 'E', 'B', 'S'},
        {'B', 'S', 'K', 'E', 'B', 'K'},
        {'D', 'D', 'D', 'D', 'D', 'E'},
        {'D', 'D', 'D', 'D', 'D', 'E'},
        {'D', 'D', 'D', 'D', 'D', 'G'}
    };

    int ans = 0;
    int n = s.size();

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            ans += solve(s, ch, i, j, n, 0, 0, 0); // Start with no direction
        }
    }

    cout << ans;
    return 0;
}
