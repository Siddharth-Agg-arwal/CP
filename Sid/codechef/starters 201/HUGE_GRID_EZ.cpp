#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        long long min_p = 0;
        min_p = s[0] - '0';
        for (int i = 1; i < n; i++)
        {
            min_p += (s[i] - '0');
            min_p += ((s[i] - '0') + (s[i - 1] - '0'));
        }

        cout << min_p << endl;
    }
}
