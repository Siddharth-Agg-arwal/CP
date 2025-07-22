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
        long long px , py, qx, qy;
        cin >> px >> py >> qx >> qy;
        vector<int> a(n);
        long long s =0;
        int m = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            s += a[i];
            m = max(m, a[i]);
        }
        long long dx = px - qx;
        long long dy = py - qy;
        long double d = sqrt(dx * dx + dy * dy);
        long double ml = std::max((long double)m, d);
        long double ts = d + (long double)s;
        if (2.0L * ml <= ts + 1e-9L)
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }

    return 0;
}
