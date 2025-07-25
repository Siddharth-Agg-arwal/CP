// tle

#include <bits/stdc++.h>
using namespace std;
static const int INF = 1e9;

int dp[31][31][51];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m, K;
        cin >> n >> m >> K;

        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                int area = i * j;
                for (int l = 0; l <= K; ++l)
                {
                    if (l == 0 || l == area)
                    {
                        dp[i][j][l] = 0;
                        continue;
                    }
                    if (l > area)
                    {
                        dp[i][j][l] = INF;
                        continue;
                    }
                    dp[i][j][l] = INF;
                    int best = INF;
                    int cost_cut_h = j * j;
                    int cost_cut_v = i * i;

                    for (int i1 = 1; i1 * 2 <= i; ++i1)
                    {
                        int i2 = i - i1;
                        int area1 = i1 * j;
                        int area2 = i2 * j;

                        int from = max(0, l - area2);
                        int to = min(l, area1);
                        for (int l1 = from; l1 <= to; ++l1)
                        {
                            int cand = dp[i1][j][l1] + dp[i2][j][l - l1] + cost_cut_h;
                            if (cand < best)
                                best = cand;
                        }
                    }
                    if (i % 2 == 1)
                    {
                        int i1 = i / 2 + 1;
                        int i2 = i - i1;
                        if (i2 > 0)
                        {
                            int area1 = i1 * j;
                            int area2 = i2 * j;
                            int from = max(0, l - area2);
                            int to = min(l, area1);
                            for (int l1 = from; l1 <= to; ++l1)
                            {
                                int cand = dp[i1][j][l1] + dp[i2][j][l - l1] + cost_cut_h;
                                if (cand < best)
                                    best = cand;
                            }
                        }
                    }

                    for (int j1 = 1; j1 * 2 <= j; ++j1)
                    {
                        int j2 = j - j1;
                        int area1 = i * j1;
                        int area2 = i * j2;

                        int from = max(0, l - area2);
                        int to = min(l, area1);
                        for (int l1 = from; l1 <= to; ++l1)
                        {
                            int cand = dp[i][j1][l1] + dp[i][j2][l - l1] + cost_cut_v;
                            if (cand < best)
                                best = cand;
                        }
                    }
                    if (j % 2 == 1)
                    {
                        int j1 = j / 2 + 1;
                        int j2 = j - j1;
                        if (j2 > 0)
                        {
                            int area1 = i * j1;
                            int area2 = i * j2;
                            int from = max(0, l - area2);
                            int to = min(l, area1);
                            for (int l1 = from; l1 <= to; ++l1)
                            {
                                int cand = dp[i][j1][l1] + dp[i][j2][l - l1] + cost_cut_v;
                                if (cand < best)
                                    best = cand;
                            }
                        }
                    }

                    dp[i][j][l] = best;
                }
            }
        }

        cout << dp[n][m][K] << "\n";
    }
    return 0;
}
