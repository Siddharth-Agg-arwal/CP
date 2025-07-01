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
        int n, k;
        cin >> n >> k;
        string s;
        int no = 0;
        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;
            s += c;
            if (c == '1')
            {
                no++;
            }
        }
        if (no <= k || (2 * k) > n)
        {
            cout << "Alice" << endl;
            continue;
        }
        // if(n  > (2 * k)-1){
        cout << "Bob" << endl;
        // continue;
        // }
        // int f=0 ;
        // for(int i = n-k-1; i<k-1; i++)
        // {
        //     if(s[i] == '1')
        //     {
        //         f=1;
        //         break;
        //     }
        // }
        // if(f == 0)
        // {
        //     cout << "Bob" << endl;
        // }
        // else
        // {
        //     cout << "Alice" << endl;
        // }
    }

    return 0;
}
