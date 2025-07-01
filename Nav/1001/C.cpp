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
        int n;
        cin >> n;

        vector<vector<int>> matrix(n, vector<int>(n));

        // Input values column-wise
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                cin >> matrix[i][j];
            }
        }

        int k = n;
        int max_val = 1;
        unordered_map<int, vector<int>> row_assignments;
        int f = 0;
        for (int i = 1; i < n; i++)
        {
            bool formable = false;
            for (int r = 0; r < n; r++)
            {
                int sum = 0;
                for (int c = n - 1; (c >= 0 && sum<i); c--)
                {
                    sum += matrix[r][c];
                    if (sum == i)
                    {
                        // cout<<i<<" "<<r<<endl;
                        row_assignments[r].push_back(i);
                        formable = true;
                        break;
                    }
                }
            }
            if (!formable)
            {
                f=1;
                cout << i << endl;
                break;
            }
        }
        if(f==0){
            cout<<n<<endl;
        }
        // cout << n - 1  << endl;
    }
    // Your code here

    return 0;
}
