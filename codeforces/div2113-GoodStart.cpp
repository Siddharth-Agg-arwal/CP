//not correct

#include <iostream>
using namespace std;

int main()
{
    int tests = 0;
    cin >> tests;

    for (int i = 0; i < tests; i++)
    {
        int w_roof = 0, h_roof = 0, w_rec = 0, h_rec = 0;
        cin >> w_roof >> h_roof >> w_rec >> h_rec;

        int x_r1 = 0, y_r1 = 0, x_r2 = 0, y_r2 = 0;
        cin >> x_r1 >> y_r1 >> x_r2 >> y_r2;

        int x_topr1 = x_r1 + w_rec, y_topr1 = y_r1 + h_rec;
        int x_topr2 = x_r2 + w_rec, y_topr2 = y_r2 + h_rec;

        int gap_x = max(x_topr1 - x_r2, x_topr2 - x_r1);
        int gap_y = max(y_r2 - y_topr1, y_r1 - y_topr2);

        if (x_r1 == x_r2)
        {
            if (gap_y >= h_rec)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            continue;
        }

        if (gap_x % w_rec == 0)
        {
            cout << "YES" << endl;
        }
        else if (gap_y >= h_rec)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}