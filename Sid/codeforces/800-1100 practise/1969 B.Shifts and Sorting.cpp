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
        string s;
        cin >> s;
        long long n = s.size();

        // long long count1s = 0;
        vector<long long> oneIndices;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                oneIndices.push_back(i + 1);
            }
        }

        if (oneIndices.size() == 0)
        {
            cout << 0 << endl;
            continue;
        }

        if (oneIndices.size() == 1)
        {
            cout << 2 * (n - oneIndices[0]) << endl;
            continue;
        }

        long long numOnes = 1;
        long long ops = 0;
        for (int i = 0; i < oneIndices.size() - 1; i++)
        {
            // cout << oneIndices[i] << " -> " << ops << " ";
            // if (oneIndices[i + 1] - oneIndices[i] == 1)
            // {
            //     numOnes += 1;
            //     continue;
            // }

            ops += (oneIndices[i + 1] - oneIndices[i] - 1) * (numOnes + 1);
            numOnes += 1;
            // cout << oneIndices[i] << " -> " << ops << ", ";
        }

        cout << ops + (numOnes + 1) * (n - oneIndices[oneIndices.size() - 1]) << endl;
    }

    return 0;
}