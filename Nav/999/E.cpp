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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> arr_n(n), arr_m(m);
        for (int i = 0; i < n; ++i)
            cin >> arr_n[i];
        for (int i = 0; i < m; ++i)
            cin >> arr_m[i];

        int s = 0;
        for (int i = 0; i < n; ++i)
            s += arr_n[i];

        // Create m x (n+1) array, last element stores original arr_n value
        vector<vector<int>> matrix(n, vector<int>(m + 1));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                matrix[i][j] = arr_n[i] - arr_m[j] & arr_n[i];
            }
            matrix[i][m] = arr_n[i];                                     // Store original value in last position
            sort(matrix[i].begin(), matrix[i].begin() + m, greater<>()); // Sort excluding the last element
        }

        // Sort rows based on first element, excluding the last element
        sort(matrix.begin(), matrix.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] > b[0]; });

        while (k-- && matrix[0][0] > 0)
        {
            s -= matrix[0][0];

            // Update the original value (last element)
            matrix[0][m] -= matrix[0][0];

            // Recalculate first row values using updated original value
            for (int j = 0; j < m; ++j)
            {
                matrix[0][j] = matrix[0][m] - arr_m[j] & matrix[0][m];
            }

            // Sort the updated row (excluding last element)
            sort(matrix[0].begin(), matrix[0].begin() + m, greater<>());

            // Find correct position for updated row
            auto updated_row = matrix[0];
            matrix.erase(matrix.begin());
            auto pos = lower_bound(matrix.begin(), matrix.end(), updated_row,
                                   [](const vector<int> &a, const vector<int> &b)
                                   {
                                       return a[0] > b[0];
                                   });
            matrix.insert(pos, updated_row);
        }

        cout << s << endl;
    }
    return 0;
}