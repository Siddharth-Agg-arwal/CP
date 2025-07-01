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
void fill(vector<int> &a, int l, int r, int &current)
{
    if (l > r)
        return;

    int mid = (l + r) / 2;
    a[mid] = current--; // Assign current number and decrement

    // Recurse left and right
    fill(a, mid + 1, r, current);
    fill(a, l, mid - 1, current);
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
        int n, k;
        cin >> n;
        vector<int> a(n);
        unordered_map<int, int> mp;
        int m =0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
            // m = max(m, mp[a[i]]);
        }
        int mm = 1;
        m = mp[a[0]];
        for (int i = 0; i < n; i++)
        {
            if(m==1){
                break;
            }
            if (mp[a[i]] < m)
            {
                m = mp[a[i]];
                mm++;
            }
            mp[a[i]]--; // Reset to avoid counting agan
        }
        cout<<mm << endl;
    }

    return 0;
}
