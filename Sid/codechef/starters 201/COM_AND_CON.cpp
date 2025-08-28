#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        string ans;
        if (n == 0)
        {
            if (m == 1)
            {
                ans = ">";
            }
            else
            {
                long long pref = 2 * m - 3;
                ans.reserve(2 * (n + m) - 1);
                for (long long i = 0; i < pref; i++)
                {
                    ans.push_back((i % 2 == 0) ? '>' : '<');
                }
                ans.push_back('=');
                ans.push_back('>');
            }
        }
        else if (m == 0)
        {
            if (n == 1)
            {
                ans = '<';
            }
            else
            {
                long long pref = 2 * n - 3;
                ans.reserve(2 * (n + m) - 1);
                for (long long i = 0; i < pref; i++)
                {
                    ans.push_back('<');
                }

                ans.push_back('=');
                ans.push_back('<');
            }
        }
        else
        {
            long long lead = 2 * n;
            ans.reserve(2 * (n + m) - 1);
            for (long long i = 0; i < lead; i++)
            {
                ans.push_back('<');
            }
            long long rem = 2 * m - 1;
            for (long long i = 0; i < rem; i++)
            {
                ans.push_back((i % 2 == 0) ? '>' : '<');
            }
        }

        cout << ans << "\n";
    }
}
