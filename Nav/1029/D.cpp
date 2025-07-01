#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }

        set<long long> st(a.begin(), a.end());

        long long total = sum;
        long long size = n + 1;

        if (total % size != 0)
        {
            cout << "NO\n";
            continue;
        }

        long long target = total / size;

        // Now check if this "missing number" to make (n+1) terms exists exactly once
        // i.e., there must be exactly one number missing such that when inserted,
        // it balances the sum to make all (n+1) terms equal to target

        // For each a[i], compute how much extra it has over "target"
        // Their total must be equal to one missing number
        int count_target = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == target)
            {
                count_target++;
            }
        }

        if (count_target >= 1 || st.find(target) == st.end())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
