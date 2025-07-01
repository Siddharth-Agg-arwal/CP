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
        vector<int> a(n);
        // unordered_map<int, int> freq;
        // unordered_map<int, pair<int , int>> d;
        int m = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            // freq[a[i]]++;
            // if (freq[a[i]] >= 2)
            // {
            //     d[a[i]].first = min(d[a[i]].first ,  i - d[a[i]].second );
            //     d[a[i]].second = i;
            // }
            // else if (freq[a[i]] == 1)
            // {
            //     d[a[i]].first = INT_MAX;
            //     d[a[i]].second = i;
            // }
            // // if(d[a[i]].first != 0 ){
            //     m = min(m, d[a[i]].first);
            // }
            
        }
        // cout << (m == INT_MAX ? -1 : m-1) << endl;
        for (int i = 0; i < n-1; ++i)
        {
            int l = a[i+1];
            // cout<< l << " " << a[i] << endl;
            if( abs(l - a[i]) <= 1)
            {
                m =0; 
                break;
            }
            for(int j = i + 2; j < n; ++j)
            {
                if((l < a[i] -1 && a[j] >= a[i] -1) || (l > a[i] +1  && a[j] <= a[i]+1))
                {
                    m= min(m, j - i -1);
                    break;
                }
                
            }
        }
        // cout<< m << endl;
        cout << (m == INT_MAX ? -1 : m) << endl;
    }

    return 0;
}
