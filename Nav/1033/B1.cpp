#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 1e9;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    if (n < 2)
    {
        cout << -1 << endl;
        return;
    }

    bool already_beautiful = false;
    for (int i = 0; i < n - 1; ++i)
    {
        if (abs(a[i] - a[i + 1]) <= 1)
        {
            already_beautiful = true;
            break;
        }
    }

    if (already_beautiful)
    {
        cout << 0 << endl;
        return;
    }

    int min_ops = INF;

    for (int j = 0; j < n - 1; ++j)
    {
        vector<int> r_min(n, INF);
        vector<int> r_max(n, -INF);
        if (j + 1 < n)
        {
            r_min[j + 1] = a[j + 1];
            r_max[j + 1] = a[j + 1];
            for (int k = j + 2; k < n; ++k)
            {
                r_min[k] = min(r_min[k - 1], a[k]);
                r_max[k] = max(r_max[k - 1], a[k]);
            }
        }

        int l_min = a[j];
        int l_max = a[j];
        int k1_ptr = n - 1;
        int k2_ptr = n - 1;

        for (int i = j; i >= 0; --i)
        {
            l_min = min(l_min, a[i]);
            l_max = max(l_max, a[i]);

            // Find smallest k >= j+1 s.t. r_max[k] >= l_min - 1
            // As i decreases, l_min decreases, so k1_ptr can only decrease.
            while (k1_ptr > j + 1 && r_max[k1_ptr - 1] >= l_min - 1)
            {
                k1_ptr--;
            }

            // Find smallest k >= j+1 s.t. r_min[k] <= l_max + 1
            // As i decreases, l_max increases, so k2_ptr can only decrease.
            while (k2_ptr > j + 1 && r_min[k2_ptr - 1] <= l_max + 1)
            {
                k2_ptr--;
            }

            int current_k1 = n;
            if (k1_ptr >= j + 1 && r_max[k1_ptr] >= l_min - 1)
            {
                current_k1 = k1_ptr;
            }

            int current_k2 = n;
            if (k2_ptr >= j + 1 && r_min[k2_ptr] <= l_max + 1)
            {
                current_k2 = k2_ptr;
            }

            int k = max(current_k1, current_k2);

            if (k < n)
            {
                min_ops = min(min_ops, (j - i) + (k - (j + 1)));
            }
        }
    }

    if (min_ops == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << min_ops << endl;
    }
}

int main()
{
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
