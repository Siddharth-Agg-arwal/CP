#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a, b;
        cin >> a >> b;
        int b_use = b / 2;
        cout << min(a, b_use) + 2 * min(a, b_use) << endl;
    }
}
