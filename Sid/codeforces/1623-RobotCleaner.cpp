#include <iostream>
using namespace std;

int main()
{
    int tests = 0;
    cin >> tests;

    for (int i = 0; i < tests; i++)
    {
        int rows = 0, cols = 0;
        cin >> rows >> cols;

        int xStart = 0, yStart = 0;
        int xDirty = 0, yDirty = 0;

        cin >> xStart >> yStart >> xDirty >> yDirty;
        int flag = 0, xTime = 0, yTime = 0, time = 0;
        // int dx = 1, dy = 1;

        if (xStart == xDirty || yStart == yDirty)
        {
            cout << time << endl;
            break;
        }

        // while (!flag)
        // {
        //     if (xStart >= rows)
        //     {
        //         dx *= -1;
        //     }
        //     else if (xStart < 0)
        //     {
        //         dx *= -1;
        //     }

        //     if (yStart >= cols)
        //     {
        //         dy *= -1;
        //     }
        //     else if (yStart < 0)
        //     {
        //         dy *= -1;
        //     }

        // if (xStart == xDirty || yStart == yDirty)
        // {
        //     cout << time << endl;
        //     break;
        // }
        // else
        // {
        //     time += 1;
        // }

        //     xStart += dx;
        //     yStart += dy;
        // }

        if (xDirty > xStart)
        {
            xTime = xDirty - xStart;
        }
        else if (xDirty < xStart)
        {
            xTime = rows - xStart + rows - xDirty;
        }

        if (yDirty > yStart)
        {
            yTime = yDirty - yStart;
        }
        else if (yDirty < yStart)
        {
            yTime = cols - yStart + cols - yDirty;
        }

        int ans = min(xTime, yTime);
        cout << ans << endl;
    }
    return 0;
}