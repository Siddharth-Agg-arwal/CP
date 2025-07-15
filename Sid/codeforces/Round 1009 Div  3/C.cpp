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
        int x;
        cin >> x;

        int lptr = 1;
        int rptr = x - 1;
        int t1 = 0, t3 = 0;
        bool possible = false;
        while (lptr < rptr)
        {
            int mptr = (lptr + rptr) / 2;
            t1 = mptr;
            t3 = mptr ^ x;

            if (t1 >= x)
            {
                rptr = mptr;
            }
            else
            {
                lptr = mptr + 1;
            }

            if (t3 < t1 + x && t3 + t1 > x && t3 + x > t1)
            {
                possible = true;
                break;
            }
        }

        if (possible)
        {
            cout << t1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}