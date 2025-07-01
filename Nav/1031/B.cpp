#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

void solve()
{
    ll w, h, a, b;
    cin >> w >> h >> a >> b;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll dx = llabs(x1 - x2);
    ll dy = llabs(y1 - y2);

    bool x_close = (dx < a);
    bool y_close = (dy < b);

    bool x_align = (dx % a == 0);
    bool y_align = (dy % b == 0);
    bool possible = false;
    if (x_close)
    {
        if (y_align)
        {
            possible = true;
        }
    }
    else if (y_close)
    {
        if (x_align)
        {
            possible = true;
        }
    }
    else
    {
        if (x_align || y_align)
        {
            possible = true;
        }
    }

    if (possible)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}