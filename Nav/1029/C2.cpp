#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

// Using std namespace for clarity in this example
using namespace std;

// Macros from your code for consistency
#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define pb push_back

// Typedefs
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 1 << endl; 
        return;
    }

    vector<int> a(n);
    map<int, vector<int>> positions;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        positions[a[i]].pb(i);
    }
    map<int, int> next_occurrence_ptr;

    int segments = 0;
    int current_segment_end = -1;
    int max_reach = 0;

    for (int i = 0; i < n; i++)
    {
        int current_val = a[i];
        int current_ptr = next_occurrence_ptr[current_val];
        int next_pos;
        if (current_ptr + 1 < positions[current_val].size())
        {
            next_pos = positions[current_val][current_ptr + 1];
        }
        else
        {
            next_pos = n;
        }
        next_occurrence_ptr[current_val]++;
        max_reach = max(max_reach, next_pos);
        if (i == current_segment_end)
        {
            segments++;
            current_segment_end = max_reach;
        }
        if (current_segment_end == -1)
        {
            segments++;
            current_segment_end = max_reach;
        }
    }

    cout << segments << endl;
}

int main()
{
    fast_io();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}