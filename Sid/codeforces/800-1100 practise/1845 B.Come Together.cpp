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
        long long x, y, bx, by, cx, cy;
        cin >> x >> y >> bx >> by >> cx >> cy;

        long long max_dist = 0;
        if ((cy - y >= 0 && by - y >= 0) || (cy - y <= 0 && by - y <= 0))
        {
            if ((bx - x >= 0 && cx - x <= 0) || (bx - x <= 0 && cx - x >= 0))
            {
                max_dist = min(abs(cy - y), abs(by - y)) + 1;
            }
            else
            {
                max_dist = min(abs(cy - y), abs(by - y)) + min(abs(cx - x), abs(bx - x)) + 1;
            }
        }
        else
        {
            if ((bx - x >= 0 && cx - x >= 0) || (bx - x <= 0 && cx - x <= 0))
            {
                max_dist = min(abs(cx - x), abs(bx - x)) + 1;
            }
            else
            {
                max_dist = 1;
            }
        }

        cout << max_dist << endl;
    }

    return 0;
}