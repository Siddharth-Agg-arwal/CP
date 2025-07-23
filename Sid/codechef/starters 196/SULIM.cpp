#include <bits/stdc++.h>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

static bool comparator(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    // your code goes here
    IOS();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> taste_sugar(n);
        for (int i = 0; i < n; i++)
            cin >> taste_sugar[i].first;
        for (int i = 0; i < n; i++)
            cin >> taste_sugar[i].second;

        sort(taste_sugar.begin(), taste_sugar.end(), comparator);

        vector<pair<int, int>> prefix;

        for (int i = 0; i < n; i++)
        {
            int curr_sugar = taste_sugar[i].second;
            int curr_sum = 0;
            while (i < n && taste_sugar[i].second == curr_sugar)
            {
                if (taste_sugar[i].first > 0)
                    curr_sum += taste_sugar[i].first;
                i += 1;
            }
            if (prefix.size() == 0)
                prefix.push_back({curr_sum, curr_sugar});
            else
                prefix.push_back({curr_sum + prefix.back().first, curr_sugar});

            i -= 1;
        }

        int max_satis = 0;
        for (int i = 0; i < prefix.size(); i++)
        {
            max_satis = max(max_satis, prefix[i].first - prefix[i].second);
        }

        cout << max_satis << endl;
    }

    return 0;
}
