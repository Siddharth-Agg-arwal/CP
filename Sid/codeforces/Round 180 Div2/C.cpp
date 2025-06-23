#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long ways = 0;
    if (n < 3)
    {
        cout << 0 << endl;
        return;
    }
    long long global_max = a[n - 1];

    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                bool cond1 = (a[i] + a[j] > a[k]);
                bool cond2 = (k < n - 1) ? (a[i] + a[j] + a[k] > global_max) : true;

                if (cond1 && cond2)
                {
                    ways++;
                }
            }
        }
    }

    cout << ways << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}