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
#define sz(x) (int)(x).size()

// Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// Constants
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

// Functions
template <typename T>
void print_vector(const vector<T> &vec)
{
    for (const auto &elem : vec)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int o(int a, int c)
{
    int m = a | c;

    // Find the most significant bit set in c
    int highestBit = 31;
    while (highestBit >= 0 && ((c >> highestBit) & 1) == 0)
        highestBit--;

    // Start from highest bit and go down
    for (int i = highestBit; i >= 0; --i)
    {
        bool bitInC = (c >> i) & 1;
        bool bitInM = (m >> i) & 1;

        if (bitInM == 1 && bitInC == 0)
        {
            // Try setting bit i to 0
            int temp = m & ~(1 << i);
            if (temp >= a)
            {
                m = temp; // Keep it as 0
            }
            // else, we keep it 1 (do nothing)
        }
    }

    return m;
}
// Main function
int main()
{
    fast_io();

    // Example input/output
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n-1);
        vector<long long> b(n);
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
        }
        long long m=0;
        b[n-1]<=a[n-2]? m = b[n-1] - a[n-2] : m = o(b[n-1], a[n-2]) - b[n-1];
        // long long m = (b[n-1] | a[n-2]) - b[n-1];
        for (int i = n-2; i >0; --i)
        {
          if (b[i]<= a[i] | a[i-1])
          {
            m+= a[i]|a[i-1] - b[i];
          }
        }
        cout<<m<<endl;
    }

    return 0;
}
