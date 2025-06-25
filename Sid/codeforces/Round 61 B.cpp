#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long num_choco;
    cin >> num_choco;
    vector<long long> bars(num_choco, 0);

    for (long long i = 0; i < num_choco; i++)
    {
        cin >> bars[i];
    }

    long long n_coupons;
    cin >> n_coupons;
    vector<long long> coupons(n_coupons, 0);
    for (long long i = 0; i < n_coupons; i++)
    {
        cin >> coupons[i];
    }

    sort(bars.begin(), bars.end());
    vector<long long> bar_sums(num_choco, 0);
    bar_sums[num_choco - 1] = bars[num_choco - 1];
    for (long long i = num_choco - 2; i >= 0; i--)
    {
        bar_sums[i] = bars[i] + bar_sums[i + 1];
    }

    long long total_val = bar_sums[0], min_coins = LONG_MAX;
    for (long long i = 0; i < n_coupons; i++)
    {
        long long curr_coupon = coupons[i];
        long long coins = bar_sums[num_choco - curr_coupon + 1];
        coins += total_val - bar_sums[num_choco - curr_coupon];
        cout << coins << endl;
    }

    // cout << min_coins << endl;
}