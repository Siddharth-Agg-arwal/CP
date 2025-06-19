#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tc = 0;
    cin >> tc;
    while (tc--)
    {
        int n, x;
        cin >> n >> x;

        if (n <= x || n == x - 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << i << " ";
            }
            cout << endl;
            // continue;
        }
        else
        {
            vector<int> ans(n, 0);
            int j = 0;
            for (int i = x; i < n; i++)
            {
                ans[j] = i;
                j += 1;
            }

            x -= 1;
            for (; j < n; j++)
            {
                ans[j] = x;
                x -= 1;
            }

            for (int i = n - 1; i >= 0; i--)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}