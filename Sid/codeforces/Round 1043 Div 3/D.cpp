#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll P10[20];
void init_p10()
{
    P10[0] = 1;
    for (int i = 1; i < 20; i++)
    {
        P10[i] = P10[i - 1] * 10;
    }
}

ll digitSumUpTo(ll n)
{
    if (n <= 0)
        return 0;
    ll res = 0;
    for (int d = 0; P10[d] <= n; d++)
    {
        ll div = P10[d];
        ll high = n / (div * 10);
        ll cur = (n / div) % 10;
        ll low = n % div;
        res += high * 45LL * div;
        res += (cur * (cur - 1) / 2) * div;
        res += cur * (low + 1);
    }
    return res;
}

ll solveOne(ll k)
{
    ll used = 0;
    ll ans = 0;
    for (int d = 1;; d++)
    {
        ll count_d = 9 * P10[d - 1];
        ll blockDigits = count_d * d;
        if (used + blockDigits <= k)
        {
            ll blockSum = digitSumUpTo(P10[d] - 1) - digitSumUpTo(P10[d - 1] - 1);
            ans += blockSum;
            used += blockDigits;
        }
        else
        {
            ll rem = k - used;
            ll fullNums = rem / d;
            ll partial = rem % d;

            ll A = P10[d - 1];
            ll B = A + fullNums - 1;

            if (fullNums > 0)
            {
                ll sumAB = digitSumUpTo(B) - digitSumUpTo(A - 1);
                ans += sumAB;
            }
            if (partial > 0)
            {
                string s = to_string(B + 1);
                for (int i = 0; i < partial; i++)
                {
                    ans += s[i] - '0';
                }
            }
            return ans;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_p10();
    int T;
    cin >> T;
    while (T--)
    {
        long long k;
        cin >> k;
        cout << solveOne(k) << "\n";
    }
    return 0;
}
