#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

// long long dp()
// {

//     if (dp[i][j] != -1)
//         return dp[i][j];
//     if(curr_amount <= lr_real[i][1] && curr_amount >= lr_real[i][0]) long long include = dp();
//     long long exclude = dp();

//     dp[i][j] = max(include, exclude);
// }

static bool comparator(const vector<int> &a, const vector<int> &b)
{
    if (a[1] == b[1])
    {
        return a[2] < b[2];
    }
    return a[1] < b[1];
}

int main()
{
    IOS();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> lr_real(n, vector<int>(3, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> lr_real[i][j];
            }
        }

        if (n == 1)
        {
            if (lr_real[0][0] <= k && lr_real[0][1] >= k)
            {
                if (k > lr_real[0][2])
                    cout << k << endl;
                else
                    cout << lr_real[0][2] << endl;
            }
            else
                cout << k << endl;
            continue;
        }

        sort(lr_real.begin(), lr_real.end(), comparator);
        long long max_real = k;
        for (int i = 0; i < n; i++)
        {
            if (k >= lr_real[i][0] && k <= lr_real[i][1])
            {
                k = lr_real[i][2];
                if (k > max_real)
                    max_real = k;
            }
        }

        cout << max_real << endl;
    }

    return 0;
}