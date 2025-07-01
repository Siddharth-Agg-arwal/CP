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
int count_pairs(const vector<int> &a, int b)
{
    int n = a.size() - 1; // exclude last
    int i = 0, j = n - 1, count = 0;

    while (i < j)
    {
        if (a[i] + a[j] > b)
        {
            count += (j - i);
            j--;
        }
        else
        {
            i++;
        }
    }
    return count;
}

int count_triplets(const vector<int> &a, int b)
{
    int n = a.size() - 1; // exclude last element
    int count = 0;

    for (int k = n - 1; k >= 2; --k)
    {
        int i = 0, j = k - 1;
        while (i < j)
        {
            int sum = a[i] + a[j] + a[k];
            if (sum > b)
            {
                count += (j - i);
                j--;
            }
            else
            {
                i++;
            }
        }
    }

    return count;
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
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int b = a[n-1];
        int pair_count = count_pairs(a, b);
        int triplet_count = count_triplets(a, b);
        cout<<pair_count + triplet_count << endl;
    }

    return 0;
}
