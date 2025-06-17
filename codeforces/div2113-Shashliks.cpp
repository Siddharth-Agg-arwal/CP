#include <iostream>
using namespace std;

int main()
{
    int tests = 0;
    cin >> tests;

    for (int i = 0; i < tests; i++)
    {
        int grill_temp = 0, t1 = 0, t2 = 0, dec1 = 0, dec2 = 0;
        cin >> grill_temp >> t1 >> t2 >> dec1 >> dec2;

        if (t1 > grill_temp && t2 > grill_temp)
        {
            cout << 0 << endl;
            continue;
        }

        int shashliks = 0;
        if (dec1 < dec2)
        {
            if (t1 <= grill_temp)
            {
                shashliks += ((grill_temp - t1) / dec1) + 1;
                grill_temp = grill_temp - shashliks * dec1;
                if (grill_temp >= t2)
                    shashliks += ((grill_temp - t2) / dec2) + 1;
            }
            else
            {
                shashliks += ((grill_temp - t2) / dec2) + 1;
            }
        }
        else
        {
            if (t2 <= grill_temp)
            {
                shashliks += ((grill_temp - t2) / dec2) + 1;
                grill_temp = grill_temp - shashliks * dec2;
                if (grill_temp >= t1)
                    shashliks += ((grill_temp - t1) / dec1) + 1;
            }
            else
            {
                shashliks += ((grill_temp - t1) / dec1) + 1;
            }
        }

        cout << shashliks << endl;
    }
}