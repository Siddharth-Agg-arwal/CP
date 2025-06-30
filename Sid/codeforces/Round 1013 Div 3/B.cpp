#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

int main()
{
    IOS();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, stren;
        cin >> n >> stren;
        vector<int> skills(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> skills[i];
        }
        sort(skills.begin(), skills.end());

        int strong_teams = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int it = 1;
            // cout << skills[i] << " ";
            while (i - it + 1 >= 0)
            {
                int curr_skill = skills[i - it + 1];
                int curr_stren = it * curr_skill;
                // cout << curr_stren << " ";
                if (curr_stren >= stren)
                {
                    strong_teams += 1;
                    break;
                }
                else
                {
                    it += 1;
                }
            }
            i -= it - 1;
        }
        // cout << endl;
        cout << strong_teams << endl;
    }

    return 0;
}