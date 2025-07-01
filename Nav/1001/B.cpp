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

    int t;
    cin >> t;
    while (t--)
    {
        int n , k;
        cin >> n >> k;
        // unordered_map<int, int> a, b;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            // int aa;
            cin >> a[i];
            // a[aa]++;
        }
        int t = k/2 - (n-k);
        int tt = n - k + 1;
        // int ts = k/2;
        int m = n;
        for(int i=1 ; i < n ;i= i + 2){
            if(a[i] != i/2 +1){
                m= min(m , i/2+1);
                break;
            }
            for(int j = 0 ; (j< tt && i+j < n) ; j++){
                if(a[i+j] != i/2 +1){
                    m = min ( m , i/2+1);
                    break;
                }
                else if(a[i+j] != i/2+2 && j!=0){
                    m= min ( m, i/2+2);
                    // break;
                }
            }
            if( m == i/2 + 1 || m == i/2+2){
                break;
            }
        }
        cout<<min( m , k/2+1)<<endl;
    }
    // Your code here

    return 0;
}
