#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    long long total_ways = 0;

    // Iterate k from the end, as k is the index of the largest element in the triplet.
    for (int k = n - 1; k >= 2; --k)
    {
        int target;
        if (k == n - 1)
        {
            // Case A: The triplet includes the largest array element.
            // Condition: a[i] + a[j] > a[k]
            target = a[k];
        }
        else
        {
            // Case B: The triplet does not include the largest array element.
            // Condition: a[i] + a[j] > max(a[k], a[n-1] - a[k])
            target = std::max(a[k], a[n - 1] - a[k]);
        }

        // Count pairs (i, j) with i < j < k s.t. a[i] + a[j] > target
        // using a two-pointer approach on the sorted prefix a[0...k-1].
        int left = 0;
        int right = k - 1;
        while (left < right)
        {
            if (a[left] + a[right] > target)
            {
                // If a[left] + a[right] works, then a[right] also works with any
                // element from a[left+1] to a[right-1].
                // There are (right - 1) - left + 1 = right - left such elements.
                total_ways += (right - left);
                right--; // Move right pointer to find more pairs.
            }
            else
            {
                left++; // a[left] is too small, try a larger value.
            }
        }
    }

    std::cout << total_ways << std::endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}