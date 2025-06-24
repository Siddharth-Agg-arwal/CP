#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> len(3, 0);
        vector<int> bre(3, 0);
        cin >> len[0] >> bre[0] >> len[1] >> bre[1] >> len[2] >> bre[2];

        if (bre[0] == bre[1] && bre[1] == bre[2] && len[0] + len[1] + len[2] == bre[0])
        {
            cout << "YES\n";
            continue;
        }

        bool lshape = false;
        for (int i = 0; i < 3; i++)
        {
            int j = (i + 1) % 3, k = (i + 2) % 3;
            if (bre[j] == bre[k] && len[j] + len[k] == len[i] && bre[i] + bre[j] == len[i])
            {
                lshape = true;
                break;
            }
        }
        if (lshape)
        {
            cout << "YES\n";
            continue;
        }

        if (len[0] == len[1] && len[1] == len[2] && bre[0] + bre[1] + bre[2] == len[0])
        {
            cout << "YES\n";
            continue;
        }

        sort(len.begin(), len.end());
        sort(bre.begin(), bre.end());
        if (len[1] == len[0] && bre[0] + bre[1] == bre[2] && bre[2] == len[2] + len[0])
            cout << "YES\n";
        else if (len[1] + len[0] == len[2] && bre[1] + bre[2] == len[2])
            cout << "YES\n";
        else if (len[1] == len[2] && bre[1] + bre[2] == bre[0] && bre[0] == len[1] + len[0])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
