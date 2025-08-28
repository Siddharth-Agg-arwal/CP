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

        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                int count = 0;
                while (s[i] == '1')
                {
                    count += 1;
                    i += 1;
                }
                if (count < 3)
                {
                    possible = false;
                    break;
                }
                i -= 1;
            }
        }

        if (possible)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
