// incomplete

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
        int n, k;
        cin >> n >> k;

        string str;
        cin >> str;

        int convert = k;
        string temp_string = "";

        int idx1 = 0, idx2 = str.size() - 1;
        while (convert / 2 > 0)
        {
            if (str[i] == '1')
                convert -= 1;
            // temp_string += '0';
            idx1 += 1;
        }

        while (convert / 2 > 0)
        {
            if (str[i] == '1')
                convert -= 1;
            idx2 -= 1;
        }

        int max_sublen1 = 0;
        if (idx1 >= idx2)
        {
            cout << "Alice\n";
            continue;
        }
        else if (n % 2 == 0)
        {
            max_sublen1 = max(idx1 - 1, n - idx2 - 1);
            if (max_sublen1 >= k)
            {
                cout << "Bob\n";
            }
            else
            {
                cout << "Alice\n";
            }
            continue;
        }

        int max_sublen2 = 0;
        convert = k;
        while (convert / 2 > 0)
        {
            if (str[i] == '1')
                convert -= 1;
            idx2 -= 1;
        }

        while (convert / 2 > 0)
        {
            if (str[i] == '1')
                convert -= 1;
            // temp_string += '0';
            idx1 += 1;
        }

        if (idx1 >= idx2)
        {
            cout << "Alice\n";
            continue;
        }

        max_sublen2 = max(max_sublen1, max(-1, n - idx2 - 1));
        if (max_sublen2 >= k)
        {
            cout << "Bob\n";
        }
        else
        {
            cout << "Alice\n";
        }

        // int from_end = 0, from_start = 0;
        // int convert = k;
        // for (int i = 0; i < str.size(); i++)
        // {
        //     if (str[i] == '1' && convert > 0)
        //     {
        //         convert -= 1;
        //         continue;
        //     }
        //     if (str[i] == '1' && convert == 0)
        //     {
        //         from_start = i;
        //         break;
        //     }
        // }

        // convert = k;
        // for (int i = str.size() - 1; i >= 0; i--)
        // {
        //     if (str[i] == '1' && convert > 0)
        //     {
        //         convert -= 1;
        //         continue;
        //     }
        //     if (str[i] == '1' && convert == 0)
        //     {
        //         from_end = i;
        //         break;
        //     }
        // }

        // if (from_end <= k || from_start >= n - k)
        // {
        //     cout << "Alice\n";
        // }
        // else
        // {
        //     cout << "Bob\n";
    }

    return 0;
}