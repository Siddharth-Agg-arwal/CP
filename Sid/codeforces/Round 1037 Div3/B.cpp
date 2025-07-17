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
    cin >> tc >> ws;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> weather(n);
        for (int i = 0; i < n; i++)
            cin >> weather[i];

        int max_hikes_possible = 0;
        for (int i = 0; i <= n - k;)
        {

            bool can_start_hike_here = true;
            for (int j = 0; j < k; ++j)
            {
                if (weather[i + j] == 1)
                {
                    can_start_hike_here = false;
                    break;
                }
            }

            if (can_start_hike_here)
            {

                max_hikes_possible++;
                i += k;
                i += 1;
            }
            else
            {
                i++;
            }
        }
        cout << max_hikes_possible << endl;
    }
    return 0;
}