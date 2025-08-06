#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

int main()
{

    string s;
    cin >> s;
    int a = 0;
    int c = 0;
    int t = 0;
    if (s[0] == 'a' || s[1] == 'a' || s[2] == 'a')
        a++;
    if (s[0] == 'c' || s[1] == 'c' || s[2] == 'c')
        c++;
    if (s[0] == 't' || s[1] == 't' || s[2] == 't')
        t++;

    if (a == 1 && c == 1 && t == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No";
    }
}