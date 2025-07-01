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
        cin>>n;
        vector<int> a(n);
        for(int i =0 ; i <n ; i++){
            cin>>a[i];
        }
        int s = 0, ss = 0;
        for (int i = 0; i < n; i++)
        {
            if(a[i]%2==0){
                s++;
            }
            else{
                ss++;
            }
        }
        if (s != 0)
        {
            cout << ss + 1 << endl;
        }
        else
        {
            cout << max(0, ss - 1) << endl;
        }
    }

    // Your code here

    return 0;
}
