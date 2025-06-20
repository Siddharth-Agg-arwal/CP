#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int tests;
    cin >> tests;

    while (tests--)
    {
        int year;
        cin >> year;

        if (floor(pow(year, 0.5)) == ceil(pow(year, 0.5)))
        {
            cout << pow(year, 0.5) << " " << 0 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}