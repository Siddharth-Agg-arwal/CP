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
        int n, x, y;
        cin >> n >> x >> y;

        int can_use = 0;
        // unordered_set<int> balls;
        for (int i = 0; i < n; i++)
        {
            int b;
            cin >> b;
            if (b >= x && b <= y)
            {
                // if(balls.find(b) == balls.end()){
                // balls.insert(b);
                can_use++;
                // }
            }
        }

        cout << can_use << endl;
    }

    return 0;
}