#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

int main()
{
    IOS();

    int riders, drivers;
    cin >> riders >> drivers;

    vector<int> coords(riders + drivers, 0);
    for (int i = 0; i < riders + drivers; i++)
    {
        cin >> coords[i];
    }

    vector<bool> driverOrNot(riders + drivers, false);
    for (int i = 0; i < riders + drivers; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
            driverOrNot[i] = true;
    }

    vector<pair<int, int>> prev_next(drivers + riders);
    int prev_driver = INT_MAX;
    unordered_map<int, int> idx_driverID;
    int j = 0;
    for (int i = 0; i < drivers + riders; i++)
    {
        if (driverOrNot[i])
        {
            idx_driverID[coords[i]] = j;
            prev_driver = coords[i];
            j += 1;
            continue;
        }
        prev_next[i].first = prev_driver;
    }

    int next_driver = -INT_MAX;
    for (int i = drivers + riders - 1; i >= 0; i--)
    {
        if (driverOrNot[i])
        {
            next_driver = coords[i];
            continue;
        }
        prev_next[i].second = next_driver;
    }

    // debug
    //  for (int i = 0; i < drivers + riders; i++)
    //  {
    //      if (!driverOrNot[i])
    //      {
    //          cout << prev_next[i].first << "," << prev_next[i].second << endl;
    //      }
    //      //prev_next[i].first = prev_driver;
    //  }

    vector<int> ans(drivers, 0);
    // int j = 0;
    for (int i = 0; i < drivers + riders; i++)
    {
        if (driverOrNot[i])
            continue;

        if (coords[i] - prev_next[i].first <= prev_next[i].second - coords[i])
        {
            ans[idx_driverID[prev_next[i].first]] += 1;
        }
        else{
            ans[idx_driverID[prev_next[i].second]] += 1;
        }

        // ans[idx_driverID[]] += 1;
    }

    for (int i = 0; i < drivers; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}