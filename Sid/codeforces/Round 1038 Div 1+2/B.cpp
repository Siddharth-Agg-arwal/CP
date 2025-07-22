#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

static bool comparator(const vector<int> &a, const vector<int> &b)
{
    return a[2] < b[2];
}

int main()
{
    IOS();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(4, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> arr[i][j];
            }
        }

        sort(arr.begin(), arr.end(), comparator);

        long long total_ops = 0;
        for (int i = 0; i < n; i++)
        {
            int top_0 = arr[i][0];
            int top_1 = arr[i][1];
            int tar_0 = arr[i][2];
            int tar_1 = arr[i][3];
            long long curr_ops = 0;

            if (top_1 > tar_1)
            {
                curr_ops += top_0 + (top_1 - tar_1);
            }
            else if (top_0 > tar_0)
            {
                curr_ops += top_0 - tar_0;
            }

            total_ops += curr_ops;
        }

        cout << total_ops << endl;
    }

    return 0;
}