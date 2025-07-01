#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int computeMaxMatch(const vector<int> &a, const vector<int> &b)
{
    int n = a.size();
    vector<int> match(n), suffixSum(n + 1, 0);

    // Step 1: Calculate match vector and suffix sums
    for (int i = 0; i < n; ++i)
        match[i] = (a[i] == b[i]) ? 1 : 0;

    for (int i = n - 1; i >= 0; --i)
        suffixSum[i] = suffixSum[i + 1] + match[i];

    // Case 1: No removal
    int maximum = 0;
    for (int i = 0; i < n; ++i)
    {
        int prefix = (a[i] == b[i]) ? i : 0;
        maximum = max(maximum, prefix + suffixSum[i]);
    }

    // Step 2: Precompute scoring vectors
    vector<int> scoreWith(n), scoreWithout(n);
    for (int i = 0; i < n; ++i)
    {
        int prefix = (a[i] == b[i]) ? i : 0;
        scoreWith[i] = prefix + suffixSum[i];
        scoreWithout[i] = prefix + suffixSum[i] - 1;
    }

    // Step 3: Prefix max of scoreWithout and suffix max of scoreWith
    vector<int> prefixMax(n + 1, INT_MIN), suffixMax(n + 1, INT_MIN);
    for (int i = 0; i < n; ++i)
        prefixMax[i + 1] = max(prefixMax[i], scoreWithout[i]);

    for (int i = n - 1; i >= 0; --i)
        suffixMax[i] = max(suffixMax[i + 1], scoreWith[i]);

    // Case 2: Consider removing a matching index
    for (int i = 0; i < n; ++i)
    {
        if (match[i] == 1)
        {
            int option = max(prefixMax[i], suffixMax[i]);
            maximum = max(maximum, option);
        }
    }

    return maximum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &x : a)
            cin >> x;
        for (int &x : b)
            cin >> x;
        cout << computeMaxMatch(a, b) << '\n';
    }
    return 0;
}
