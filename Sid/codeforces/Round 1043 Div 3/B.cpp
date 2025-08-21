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
        long long n;
        cin >> n;

        string s = to_string(n);
        int str_len = s.length();

        vector<string> ans;

        for (int k = 1; k <= str_len; k++)
        {
            long long p = 1;
            for (int i = 0; i < k; i++)
                p *= 10;
            long long m = p + 1;
            if (m > n)
                break;

            if (n % m == 0)
            {
                long long x = n / m;
                if (x > 0)
                    ans.push_back(to_string(x));
            }
        }

        if (ans.empty())
        {
            cout << 0 << "\n";
        }
        else
        {
            sort(ans.begin(), ans.end(), [](const string &a, const string &b)
                 {
                if (a.size() != b.size()) return a.size() < b.size();
                return a < b; });

            cout << ans.size() << endl;
            for (auto &x : ans)
                cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}
