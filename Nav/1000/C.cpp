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
// #include <algorithm>
#include <numeric>
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
int sum(const vector<int> &vec){
    int s = 0;
    for (const auto &elem : vec)
    {
        s+= elem;
    }
    return s;
}

int sol(vector<int> a, int n)
{
    // Base case: if there is only one element, return that element
    if (n == 1)
    {
        return a[0];
    }

    // Compute the sum of the array
    int sum = accumulate(a.begin(), a.end(), 0);

    // Create a copy of the array to modify for the first iteration
    vector<int> b = a;
    int p = b[0];
    for (int i = 1; i < n; i++)
    {
        int pp = b[i];
        b[i] -= p;
        p = pp;
    }
    b.erase(b.begin());
    int result1 = sol(b, n-1);

    // Reverse the array and modify it for the second iteration
    reverse(a.begin(), a.end());
    p = a[0];
    for (int i = 1; i < n; i++)
    {
        int pp = a[i];
        a[i] -= p;
        pp = p;
    }
    a.erase(a.begin());
    int result2 = sol(a, n-1);
    // print_vector(b);
    // print_vector(a);
    // cout<<sum<<" "<<result1<<" "<<result2<<" "<<n<<endl;

    // Return the maximum of the three values: sum, result1, and result2
    return max({sum, result1, result2});
}
    // Main function
int main()
{
    fast_io();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        // vector<pair<int , int>> a(n);
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            // int aa;
            // cin>>aa;
            // a[i].first = aa;
            // a[i].second = i+1;
            cin >> a[i];
        }
        // sort(a.begin() , a.end() , [](auto a , auto b){ return a.first<b.first ;});
        // vector<int> s(n) , sr(n);
        // s[0] = a[0];
        // sr[0] = a[n-1];
        // for(int i = 1 ; i< n ; i++){
        //     s[i] = s[i-1] + a[i];
        //     sr[i] = sr[i-1] + a[n-1-i];
        // }
        // int ans = s[n-1];
        // vector<int> m = {1 ,1};
        // // print_vector(s);
        // for(int i = 1 ; i <= n-1; i++){
        //     // ans = max(ans , s[i-1] + sr[n-i-1] );
        //     int sum =0;
        //     int sumr = 0;
        //     for(int j=0 ; j < m.size() ; j++){
                
        //         if(j%2 == 0){
        //             sum += m[j] * (s[n-1 - j] - ((i-j-1 < 0) ? 0 : s[ i-j-1]));
        //             sumr += m[j] * (sr[n - 1 - j] - ((i - j - 1 < 0) ? 0 : sr[i - j - 1]));
        //         }
        //         else{
        //             sum -= m[j] * (s[n - 1 - j] - ((i - j - 1 < 0) ? 0 : s[i - j - 1]));
        //             sumr -= m[j] * (sr[n - 1 - j] - ((i - j - 1 < 0) ? 0 : sr[i - j - 1]));
        //         }
        //         // cout << m[j] * (sr[n - 1 - j] - ((i - j - 1 < 0) ? 0 : sr[i - j - 1])) << " s" << sumr << " ";
        //     }
        //     // cout<<endl;
        //     // print_vector(m);
        //     int p = 1;
        //     for(int j = 1 ; j<m.size(); j++){
        //        int  pp = m[j];
        //         m[j] += p;
        //         p = pp;
        //     }
        //     m.push_back(1);
        //     // print_vector(m);
        //     // cout<<ans<<" "<<sum<<" "<<sumr<<" "<<i<<endl;
        //     ans = max( ans , max(abs(sum) , abs(sumr)));
        //     // if(i ==  n -1 ){
        //     //     ans = max(ans , abs(sum));
        //     // }
        // }
        int ans = sol ( a , n);
        cout<<ans<<endl;
    }
    // Your code here

    return 0;
}
