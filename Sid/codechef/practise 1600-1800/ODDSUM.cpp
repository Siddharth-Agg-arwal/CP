#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        long long n;
        cin >> n;

        // long long t = n - 1;
        long long sum = (long long)(n - 1) * (long long)(n - 2) + 1;
        cout << sum << "\n";
    }
}
