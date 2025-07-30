#include <bits/stdc++.h>
using namespace std;

pair<int, int> gcdd(int a, int b)
{
    int g = gcd(a, b);
    a /= g;
    b /= g;
    return {a, b};
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int count_d = 0;
        int count_k = 0;
        map<pair<int, int>, int> m;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'D')
                count_d += 1;
            else if (s[i] == 'K')
                count_k += 1;

            cout << ++m[gcdd(count_d, count_k)] << " ";
            // int dividor = min(count_d, count_k);
            // int dividee = max(count_d, count_k);

            // if (dividor == 0)
            // {
            //     cout << dividee << " ";
            //     continue;
            // }
            // else
            // {
            //     int val = dividee % dividor;
            //     if (val != 0)
            //     {
            //         cout << 1 << " ";
            //     }
            //     else
            //     {
            //         if (dividee == dividor)
            //         {
            //             cout << dividor << " ";
            //             continue;
            //         }
            //         if ((dividee / dividor) % 2 == 1)
            //         {
            //             cout << 1 << " ";
            //             continue;
            //         }
            //         // else if(dividor != dividee && dividor == 2){
            //         //     cout << 1 << " ";
            //         //     continue;
            //         // }
            //         cout << dividor << " ";
            //     }
            // }
        }

        cout << endl;
    }
}

// 1 2 3 1 1 1 1 1 2 1 1 3 1 2 1 1 1 1 1 1 1 1 1 1 1 1 2 1 1 1