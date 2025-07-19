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
        int n;
        cin >> n;

        vector<vector<int>> x_sorted(n, vector<int>(4));
        vector<vector<int>> y_sorted(n, vector<int>(4));

        for (int i = 0; i < n; i++)
        {
            cin >> x_sorted[i][1] >> x_sorted[i][2];
            x_sorted[i][0] = x_sorted[i][1] + x_sorted[i][2];
            y_sorted[i][0] = x_sorted[i][1] - x_sorted[i][2];
            y_sorted[i][1] = x_sorted[i][1];
            y_sorted[i][2] = x_sorted[i][2];
            x_sorted[i][3] = i + 1;
            y_sorted[i][3] = i + 1;
        }

        sort(x_sorted.begin(), x_sorted.end());
        sort(y_sorted.begin(), y_sorted.end());

        long long max_val1 = 0, max_val2 = 0;
        int half = n / 2;

        for (int i = 0; i < half; i++)
        {
            int j = n - 1 - i;
            long long dx1 = (long long)x_sorted[i][1] - x_sorted[j][1];
            long long dy1 = (long long)x_sorted[i][2] - x_sorted[j][2];
            max_val1 += llabs(dx1) + llabs(dy1);

            long long dx2 = (long long)y_sorted[i][1] - y_sorted[j][1];
            long long dy2 = (long long)y_sorted[i][2] - y_sorted[j][2];
            max_val2 += llabs(dx2) + llabs(dy2);
        }

        if (max_val1 < max_val2)
        {
            for (int i = 0; i < half; i++)
            {
                int j = n - 1 - i;
                cout << y_sorted[i][3] << " " << y_sorted[j][3] << "\n";
            }
        }
        else
        {
            for (int i = 0; i < half; i++)
            {
                int j = n - 1 - i;
                cout << x_sorted[i][3] << " " << x_sorted[j][3] << "\n";
            }
        }
    }
    return 0;
}
