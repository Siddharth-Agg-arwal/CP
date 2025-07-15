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
        int n;
        cin >> n;
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        if (nums.size() == 1)
        {
            cout << nums[0] << endl;
            continue;
        }

        sort(nums.begin(), nums.end());
        queue<int> nums_q;
        for (int i = 0; i < n; i++)
        {
            nums_q.push(nums[i]);
        }

        while (!nums_q.empty())
        {
            int t1 = nums_q.front();
            nums_q.pop();
            int t2 = nums_q.front();
            nums_q.pop();
            if (nums_q.empty())
            {
                cout << t1 + t2 - 1 << endl;
                break;
            }
            else
            {
                nums_q.push(t1 + t2 - 1);
            }
        }
    }

    return 0;
}