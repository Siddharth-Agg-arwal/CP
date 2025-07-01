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
        int n , m;
        cin>>n>>m;
        vector<int> sol(n);
        int i;
        int f=0;
        for(i=0;i<n;i++){
            vector<int> car(m);
            for(int j = 0 ; j<m ; j++){
                cin>>car[j];
            }
            if(f==0){sort(car.begin(),car.end());
            if(car[0]>n){
                break;
            }
            else{
                sol[car[0]] = i+1;
                int l;
                for (l = 1; l < m; l++)
                {
                    if(car[l]- car[l-1] != n){
                        break;
                    }
                }
                if(l!=m){
                    f=1;
                }
            }}
        }
        if(f==1){
            cout<<-1<<endl;
        }
        else{
            print_vector(sol);
        }
    }

    // Your code here

    return 0;
}
