#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> w, c;
    long long pw = 1;
    for (int x = 0;; x++)
    {
        if (pw > 1000000000LL)
            break;
        w.push_back(pw);
        long long cost = pw * 3;
        if (x > 0)
            cost += (long long)x * (pw / 3);
        c.push_back(cost);
        pw *= 3;
    }

    int T;
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;

        long long answer = 0;
        for (int i = (int)w.size() - 1; i >= 0; i--)
        {
            if (n >= w[i])
            {
                long long cnt = n / w[i];
                answer += cnt * c[i];
                n -= cnt * w[i];
            }
        }

        cout << answer << "\n";
    }
    return 0;
}
