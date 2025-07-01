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
        int a ,x, y;
        cin >> a >> x >> y;
        int d = abs(x - y)%2 == 0 ? abs(x - y) / 2 : abs(x - y) / 2 + 1;
        int mi = min(x, y) , ma = max(x, y);
        if(a<mi || a>ma){
            cout<< "YES" << endl;
            continue;
        }
        // if (abs(x-a) > d && abs(y-a) > d)
        // {
        //     cout << "YES" << endl;
        //     continue;
        // } 
        cout << "NO" << endl;


    }

    return 0;
}
