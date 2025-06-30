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
        int num0s = 3, num1s = 1, num2s = 2, num3s = 1, num5s = 1;
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        bool assigned = false;

        int i = 0;
        for (; i < n; i++)
        {
            if (num0s <= 0 && num1s <= 0 && num2s <= 0 && num3s <= 0 && num5s <= 0)
            {
                assigned = true;
                cout << i << endl;
                break;
            }
            if (nums[i] == 0)
                num0s--;
            else if (nums[i] == 1)
                num1s--;
            else if (nums[i] == 2)
                num2s--;
            else if (nums[i] == 3)
                num3s--;
            else if (nums[i] == 5)
                num5s--;
        }

        if (!assigned && num0s <= 0 && num1s <= 0 && num2s <= 0 && num3s <= 0 && num5s <= 0)
        {
            assigned = true;
            cout << i << endl;
        }

        if (!assigned)
            cout << 0 << endl;
    }

    return 0;
}