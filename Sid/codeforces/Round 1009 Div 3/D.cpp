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
        set<pair<int, int>> points;
        int n, m;
        cin >> n >> m;
        vector<int> centres(n);
        vector<int> radii(n);
        for (int i = 0; i < n; i++)
            cin >> centres[i];
        for (int i = 0; i < n; i++)
            cin >> radii[i];

        // x points
        // for (int j = centres[i] - radii[i]; j <= centres[i] + radii[i]; j++)
        // {
        //     points.insert({j, 0});
        //     points.insert({centres[i], j});
        // }

        // // diagonal 1
        // for (int j = centres[i] - radii[i] - 1; j <= centres[i] + radii[i]; j++)
        // {
        //     points.insert({j, j});
        // }

        for (int i = 0; i < n; i++)
        {
            int cx = centres[i];
            int cy = 0;
            int r = radii[i];
            long long r2 = 1LL * r * r;

            for (int x = cx - r; x <= cx + r; x++)
            {
                long long dx2 = 1LL * (x - cx) * (x - cx);
                int dy_max = (int)floor(sqrt(r2 - dx2));

                for (int y = cy - dy_max; y <= cy + dy_max; y++)
                {
                    points.insert({x, y});
                }
            }
        }

        cout << points.size() << endl;
    }

    return 0;
}