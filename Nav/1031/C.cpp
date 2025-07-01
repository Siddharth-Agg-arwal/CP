#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to solve a single test case
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
    }

    // Create a 2D prefix sum array for gold counts
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + (grid[i][j] == 'g');
        }
    }

    // Helper function to query the number of gold pieces in a rectangle
    // Handles out-of-bounds coordinates by clamping them to the grid dimensions
    auto query = [&](int r1, int c1, int r2, int c2)
    {
        r1 = max(0, r1);
        c1 = max(0, c1);
        r2 = min(n - 1, r2);
        c2 = min(m - 1, c2);

        if (r1 > r2 || c1 > c2)
        {
            return 0;
        }

        return pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
    };

    int max_gold = 0;

    // Iterate through all cells to find potential dynamite locations
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            // Dynamite can only be placed in an empty cell
            if (grid[i][j] == '.')
            {
                // Calculate gold on the boundary using the principle of inclusion-exclusion
                // Gold on boundary = (Gold in outer square) - (Gold in inner square)

                // Outer square (explosion radius k)
                int outer_r1 = i - k, outer_c1 = j - k;
                int outer_r2 = i + k, outer_c2 = j + k;
                int outer_gold = query(outer_r1, outer_c1, outer_r2, outer_c2);

                // Inner square (gold to be destroyed, radius k-1)
                int inner_r1 = i - k + 1, inner_c1 = j - k + 1;
                int inner_r2 = i + k - 1, inner_c2 = j + k - 1;
                int inner_gold = query(inner_r1, inner_c1, inner_r2, inner_c2);

                int current_gold = outer_gold - inner_gold;
                max_gold = max(max_gold, current_gold);
            }
        }
    }

    cout << max_gold << endl;
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}