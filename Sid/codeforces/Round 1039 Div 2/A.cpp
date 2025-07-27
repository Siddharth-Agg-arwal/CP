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
        int n, k;
        cin >> n >> k;
        priority_queue<long long> nums;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            nums.push(a);
        }

        int multiplier = 1;
        long long coins = 0;
        while (!nums.empty())
        {
            if (nums.top() * multiplier > k)
            {
                coins += 1;
                nums.pop();
                continue;
            }
            else if (nums.top() * multiplier <= k)
            {
                multiplier *= 2;
                nums.pop();
                continue;
            }
        }

        cout << coins << endl;
    }

    return 0;
}