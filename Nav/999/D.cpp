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
unordered_map<int, int> a;
bool ff ( int num){
    int a1 , a2;
    bool r = true;
    if(num == 0 && a[num] == 0){
        return false;
    }
    if(num%2 ==0 ){
        a1 = num /2;
        a2 = num /2;
    }
    else{
        a1 = num/2;
        a2 = num / 2 +1 ;
    }
    // cout<<a1<<a2<<endl;
    if(a[a1]){
        a[a1]--;
    }
    else{
        r = ff(a1);
        if(!r){
            return false;
        }
    }
    if(a[a2]){
        a[a2]--;
    }
    else{
        r = ff(a2);
        if(!r){
            return false;
        }
    }
    return true;
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
        int n , m;
        cin >> n >> m ;
        // cout<<"hi";
        a.clear();
        for (int i = 0; i < n; i++)
        {
            int a1;
            cin >> a1;
            a[a1]++;
        }
        vector<int> aa(m);
        for(int i = 0 ; i< m ; i++){
            cin >> aa[i] ;
        }
        int f=0;
        for(int i = 0 ; i < m ; i++){
            if(a[aa[i]]){
                // cout<<a[aa[i]];
                a[aa[i]]--;
                // cout<<"hi";
                continue;
            }
            // cout<<"hi";
            if(!ff(aa[i])){
                cout<<"No"<<endl;
                f =1 ;
                break;
            }
        }
        if(f == 0){
        for(auto l : a){
            if(l.second > 0){
                cout<<"No"<<endl;
                f =1;
                break;
            }
        }
        if(f==0){
            cout<<"Yes"<<endl;
        }}
    }

    // Your code here

    return 0;
}
