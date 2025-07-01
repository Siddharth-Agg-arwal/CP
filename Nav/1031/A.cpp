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
        int a,b,x,y,k;
        int p =0;
        cin >> k >> a >> b >> x >> y;
        if(x<=y){
            if(a<k){p+= (k-a)/x;
            k -= p*x;}
            if (a <= k)
            {
                p += 1;
                k -= x;
            }
            // cout<<p<<k<<b<<endl;
            if( b<k){

                int t = (k-b)/y;
                p+=t;
                k -= t*y;
            }
            // cout << p << " " << k << b << endl;
            if (b <= k)
            {
                p += 1;
                k -= y;
            }
        }
        else if (y < x)
        {
            if (b<k){ p += (k - b ) / y;
            k -= p * y;}
            if (b <= k)
            {
                p += 1;
                k -=  y;
            }
            // cout << p << k << a <<x<< endl;
            if (a < k)
            {
                int t = (k - a ) / x;
                p+= t;
                k -= t * x;
            }
            if (a <= k)
            {
                p += 1;
                k -= x;
            }
        }
        cout<<p<<endl;
    }

    return 0;
}


// 10 5 3 3 4