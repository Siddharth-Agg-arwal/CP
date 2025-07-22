#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

int main()
{
    IOS();
    int tc;
    cin >> tc;
    while (tc--)
    {
        // int n, k, a1, ak;
        // cin >> n >> k >> a1 >> ak;

        // int a1_req = n % k, ak_req = n / k;
        // int min_coins = a1_req + ak_req;
        // int fancy_coins = 0;
        // if (a1 >= a1_req && ak >= ak_req)
        // {
        //     cout << fancy_coins << endl;
        //     continue;
        // }
        // else if (a1 >= a1_req && ak < ak_req && a1 != 0)
        // {
        //     int a1_used = ((a1 - a1_req) - ((a1 - a1_req) % k));
        //     // cout << a1_used/k << " " << ak_req << " - ";
        //     int ak_used = ak + (a1_used / k);
        //     fancy_coins = ak_req - ak_used;
        //     // cout << ak_req << " " << ak_used << " " << ak << " - ";
        // }
        // else if (ak >= ak_req && a1 != 0 && a1 < a1_req)
        // {
        //     int ak_used = 0;
        //     if (k <= a1_req)
        //     {
        //         ak_used = ak_req + min(ak - ak_req, (a1_req - a1) / k);
        //     }
        //     fancy_coins = a1 - a1_req - ak_used;
        // }
        // else
        // {

        //     fancy_coins = min_coins - (a1_req, a1) - min(ak_req, ak);
        // }

        // cout << fancy_coins << endl;
        int m, k, a1, ak;
        cin >> m >> k >> a1 >> ak;
        int taken_k = m / k;
        int taken_1 = m % k;
        int taken_fancy_1 = max(0, taken_1 - a1);
        int left_regular_1 = max(0, a1 - taken_1);
        int taken_fancy_k = max(0, taken_k - ak);
        int to_replace = min(left_regular_1 / k, taken_fancy_k);
        int ans = taken_fancy_1 + taken_fancy_k - to_replace;
        cout << ans << endl;
    }

    return 0;
}

// 1 1 1 0 1 2