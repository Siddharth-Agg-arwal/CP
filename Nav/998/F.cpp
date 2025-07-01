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
        int k, n; // 'n' is unused but kept for input structure
        cin >> k >> n;
        unordered_map<int, vector<int>> p;
        p[1] = {};
        for(int i=2;i<k+1;i++){
            int n = i;
            for(int j =2 ; j * j < i ; j++){
                while(n%j==0){
                    p[i].push_back(j);
                    n/=j;
                    break;
                }
            }
            if(n == i){
                p[i].push_back(n);
            }
            else{
                p[i].insert( p[i].end() ,  p[n].begin() , p[n].end());
            }
            int a = p[i].size();
            for(int l=0;l<n;l++){
                
            }
        }

    }

    // Your code here

    return 0;
}
