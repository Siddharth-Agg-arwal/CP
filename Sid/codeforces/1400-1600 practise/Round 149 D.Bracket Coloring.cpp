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
        int n;
        cin >> n;
        string brackets;
        cin >> brackets;

        int count_conv = 0;
        int count_conc = 0;

        for (int i = 0; i < n; i++)
        {
            (brackets[i] == ')' ? count_conc++ : count_conv++);
        }
        if (count_conc != count_conv)
        {
            cout << -1 << endl;
            continue;
        }

        stack<char> parentheses;
        for (int i = 0; i < n; i++)
        {
            if (brackets[i] == '(')
                parentheses.push('(');
            else if (parentheses.empty())
            {
                parentheses.push(')');
                break;
            }
            else
            {
                parentheses.pop();
            }
        }

        if (parentheses.empty())
        {
            cout << 1 << endl;
            for (int i = 0; i < n; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;
            continue;
        }

        deque<int>
            indices;
        vector<bool> colors(n, false);
        // bool color2 = false;
        for (int i = 0; i < n; i++)
        {
            if (brackets[i] == ')')
                indices.push_back(i);
            else if (brackets[i] == '(' && !indices.empty())
            {
                // color2 = true;
                int idx1 = i;
                int idx2 = indices.front();
                indices.pop_front();
                colors[idx1] = true;
                colors[idx2] = true;
            }
        }

        bool color2 = false;
        for (int i = 1; i < colors.size(); i++)
        {
            if (colors[i] != colors[i - 1])
            {
                color2 = true;
                cout << 2 << endl;
                break;
            }
        }

        if (!color2)
            cout << 1 << endl;

        int coloring1 = 2;
        int coloring2 = 1;
        if (!color2)
        {
            coloring1 = 1;
            coloring2 = 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (colors[i] == true)
                cout << coloring1 << " ";
            else
                cout << coloring2 << " ";
        }

        cout << endl;
    }

    return 0;
}