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
        int n, k;
        string s;
        cin >> n >> k >> s;

        int c0 = 0, c1 = 0, p0 = 0, p1 = 0;
        for (char ch : s)
        {
            if (ch == '0')
            {
                if (++c0 == 2)
                {
                    ++p0;
                    c0 = 0;
                }
            }
            else
            {
                if (++c1 == 2)
                {
                    ++p1;
                    c1 = 0;
                }
            }
        }

        int delta = p1 - p0 + k;
        if (delta % 2 != 0)
        {
            cout << "NO\n";
            continue;
        }
        int x = delta / 2;
        int y = k - x;
        if (0 <= x && x <= p1 && 0 <= y && y <= p0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
