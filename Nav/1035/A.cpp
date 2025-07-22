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
        int a,b,x,y;
        cin >> a >> b >> x >> y;
        if(a==b){
            cout<<0<<endl;
            continue;
        }
        if(a>b+1){
            cout<<-1<<endl;
            continue;
        }
        if(a==b+1 && a%2 == 1){
            cout<<y<<endl;
            continue;
        }
        else if(a==b+1 && a%2 == 0){
            cout<<-1<<endl;
            continue;
        }
        if(a<b){
            if(x<y){
                cout<<(b-a)*x<<endl;
                continue;
            }
            else{
                if((b-a)%2 == 0){
                    cout<<((b-a)/2)*x + ((b-a)/2)*y<<endl;
                    continue;
                }
                else if(a%2 == 0){
                    cout<<((b-a)/2)*x + ((b-a)/2+1)*y<<endl;
                    continue;
                }
                else{
                    cout<<((b-a)/2 +1)*x + ((b-a)/2)*y<<endl;
                    continue;
                }
            }
        }
    }

    return 0;
}
