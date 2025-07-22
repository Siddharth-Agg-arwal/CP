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
long long nextPowerOfTwo(long long n)
{
    n--;

    // Propagate the highest set bit to all lower bits.
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32; // Added for 64-bit integers

    // Incrementing n results in the next power of two.
    n++;

    return n;
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
        long long n, l, r, k;
        cin >> n >> l >> r >> k;
        if (n % 2 == 1)
        {
            cout << l << endl;
            continue;
        }
        else if( n ==2){
            cout<<-1 << endl;
        }
        else
        {
            long long r1 = nextPowerOfTwo(l);
            if (k < n - 1)
            {
                if (r1 == l)
                {
                    r1 = r1 * 2;
                }
                if (r1 <= r)
                {
                    cout << l << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
            }
            else
            {
                // cout<<l;
                
                if(r1 == l){
                    r1 = r1 *2;
                }
                if (r1 <= r)
                {
                    cout << r1 << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
            }
        }
    }

    return 0;
}
