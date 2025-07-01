#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <climits>
#include <cassert>

using namespace std;

// Macros
#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (long long)(x).size()

// Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef vector<ll> vll;
typedef pair<long long, long long> pii;
typedef pair<ll, ll> pll;

// Constants
const long long MOD = 1e9 + 7;
const double EPS = 1e-9;

int main()
{
    fast_io();

    ll testCases;
    cin >> testCases;
    while (testCases--)
    {
        ll arrSize;
        cin >> arrSize;

        vector<ll> arrVec(arrSize);
        unordered_map<ll, ll> freqMap;

        // Count frequency of each element (only those <= n)
        for (ll i = 0; i < arrSize; i++)
        {
            cin >> arrVec[i];
            if (arrVec[i] <= arrSize)
                freqMap[arrVec[i]]++;
        }

        // Difference array for range updates on valid k's
        vector<ll> diffArr(arrSize + 2, 0); // +2 to handle edge safely

        // Iterate over m from 0 to n
        for (ll mVal = 0; mVal <= arrSize; mVal++)
        {
            ll minValid = freqMap[mVal];
            ll maxValid = arrSize - mVal;

            // Valid k is in [minValid, maxValid]
            if (minValid <= maxValid)
            {
                diffArr[minValid]++;
                if (maxValid + 1 <= arrSize)
                    diffArr[maxValid + 1]--;
            }

            // Stop if m is not present in input
            if (freqMap[mVal] == 0)
                break;
        }

        ll curSum = 0;
        for (ll k = 0; k <= arrSize; k++)
        {
            curSum += diffArr[k];
            cout << curSum << " ";
        }
        cout << "\n";

        /*
        for (ll i = 0; i <= arrSize; i++) {
            ll count = 0;
            for (auto &x : freqMap) {
                if (x.second <= i && x.first <= arrSize - i) {
                    count++;
                }
            }
            cout << count + 1 << " "; // This always overcounts
        }
        cout << endl;
        */
    }

    return 0;
}
