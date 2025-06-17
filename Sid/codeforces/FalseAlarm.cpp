#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tests = 0;
    cin >> tests;

    for (int i = 0; i < tests; i++)
    {
        int numdoors = 0, timer = 0;
        cin >> numdoors >> timer;
        vector<bool> door_status(numdoors, 0);
        for (int j = 0; j < numdoors; j++)
        {
            bool val = 0;
            cin >> val;
            door_status[j] = val;
        }

        int firstone = -1;
        int lastone = -1;
        for (int j = 0; j < numdoors; j++)
        {
            if (door_status[j] == 1)
            {
                if (firstone == -1)
                {
                    firstone = j;
                }
                else
                {
                    lastone = j;
                }
            }
        }

        if (lastone - firstone >= timer)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}