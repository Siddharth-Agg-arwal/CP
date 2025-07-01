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
    // fast_io();

    // Example input/output
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        // cout<<"hi";
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<>());
        int mn = 0;
        int a1;
        // print_vector(a);
        for (int i = 0; i < n -1 ; i++)
        {
            if(a[i] == a[i+1]){
                mn = a[i];
                // a1 = i;
                a.erase(a.begin() + i , a.begin() + i +2);
                break;
            }
        }
        // print_vector(a);
        if(mn ==0 ){
            cout<<-1<<endl;
        }
        else{
            int f = 0;
           for(int i = n- 3 ; i > 0 ; i--){
            if(a[i-1] - a[i] < 2*mn){
                cout << a[i] << " " << a[i - 1] << " " << mn << " " << mn << endl;
                f = 1;
                break;
            }
           }
           if(f == 0){
            cout<<-1<<endl;
           }
        }
    }

    // Your code here

    return 0;
}
