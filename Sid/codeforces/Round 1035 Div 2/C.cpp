#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        long long n, l, r, k;
        cin >> n >> l >> r >> k;

        if (n & 1LL)
        {
            cout << l << "\n";
            continue;
        }
        uint64_t P = 1;
        while (P <= (uint64_t)l)
        {
            P <<= 1;
            if (P == 0)
            {
                cout << -1 << "\n";
                continue;
            }
        }

        if (P > (uint64_t)r)
        {
            cout << -1 << "\n";
        }
        else
        {
            if (n == 2)
            {
                cout << -1 << "\n";
            }
            else
            {
                if (k <= n - 2)
                {
                    cout << l << "\n";
                }
                else
                {
                    cout << P << "\n";
                }
            }
        }
    }
    return 0;
}
