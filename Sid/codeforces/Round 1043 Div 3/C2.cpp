#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL << 60);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> w;
    vector<ll> cost;
    {
        ll pw = 1;
        for (int x = 0; pw <= 100000; x++)
        {
            w.push_back((int)pw);
            ll c = pw * 3 + (x > 0 ? (ll)x * (pw / 3) : 0);
            cost.push_back(c);
            pw *= 3;
        }
    }
    int D = w.size();

    int T;
    cin >> T;
    while (T--)
    {
        int n, K;
        cin >> n >> K;

        static ll dp[1001][1001];
        if (K > 1000 || n > 1000)
        {
            ll rem = n, deals = 0, ans = 0;
            for (int i = D - 1; i >= 0; i--)
            {
                if (rem >= w[i])
                {
                    ll cnt = rem / w[i];
                    deals += cnt;
                    ans += cnt * cost[i];
                    rem -= cnt * w[i];
                }
            }
            if (rem != 0 || deals > K)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << ans << "\n";
            }
            continue;
        }

        for (int d = 0; d <= K; d++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[d][j] = INF;
            }
        }
        dp[0][0] = 0;

        for (int d = 0; d < K; d++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (dp[d][j] == INF)
                    continue;
                for (int t = 0; t < D; t++)
                {
                    int jj = j + w[t];
                    if (jj > n)
                        break;
                    dp[d + 1][jj] = min(dp[d + 1][jj], dp[d][j] + cost[t]);
                }
            }
        }

        ll best = INF;
        for (int d = 1; d <= K; d++)
        {
            best = min(best, dp[d][n]);
        }
        cout << (best == INF ? -1 : best) << "\n";
    }
    return 0;
}
