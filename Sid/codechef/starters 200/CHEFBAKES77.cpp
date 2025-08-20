#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int n, x, y;
    cin >> n >> x >> y;

    int cakepervan = floor((double)y / (double)x);
    // cout << cakepervan << endl;
    cout << ceil((double)n / (double)cakepervan);
}
