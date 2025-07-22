#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

static bool comparator(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}

int main()
{
    IOS();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> cards(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> cards[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            sort(cards[i].begin(), cards[i].end());
        }

        for (int i = 0; i < n; i++)
        {
            cards[i].push_back(i + 1);
        }

        sort(cards.begin(), cards.end(), comparator);

        bool possible = true;
        for (int i = 0; i < m; i++)
        {
            if (i > 0)
            {
                if (cards[n - 1][i - 1] > cards[0][i])
                    possible = false;
            }
            for (int j = 1; j < n; j++)
            {
                if (cards[j][i] < cards[j - 1][i])
                    possible = false;
            }
        }

        if (possible)
        {
            for (int i = 0; i < n; i++)
            {
                cout << cards[i][m] << " ";
            }
            cout << endl;
        }
        else
            cout << -1 << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m + 1; j++)
        //     {
        //         cout << cards[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }

    return 0;
}