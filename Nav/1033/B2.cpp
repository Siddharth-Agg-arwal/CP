#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// A large integer value to represent infinity, used for finding the minimum.
const int INF = 1e9;

void solve()
{
    int n;
    std::cin >> n;
    std::vector<long long> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    // Check if the array is already beautiful (0 operations needed).
    for (int i = 0; i < n - 1; ++i)
    {
        if (std::abs(arr[i] - arr[i + 1]) <= 1)
        {
            std::cout << 0 << std::endl;
            return;
        }
    }

    int min_operations = INF;

    // The core idea is to find the minimum operations to make two adjacent blocks beautiful.
    // We iterate through all possible split points in the array.
    // The split is between `arr[split_idx]` and `arr[split_idx + 1]`.
    for (int split_idx = 0; split_idx < n - 1; ++split_idx)
    {

        // Precompute running min/max for the right side of the split.
        // `right_min[k]` will store the minimum of `arr[split_idx + 1 ... k]`.
        std::vector<long long> right_min(n, INF);
        std::vector<long long> right_max(n, -INF);

        right_min[split_idx + 1] = arr[split_idx + 1];
        right_max[split_idx + 1] = arr[split_idx + 1];
        for (int k = split_idx + 2; k < n; ++k)
        {
            right_min[k] = std::min(right_min[k - 1], arr[k]);
            right_max[k] = std::max(right_max[k - 1], arr[k]);
        }

        long long left_min;
        long long left_max;

        // Two pointers to find the minimum required length of the right block.
        // As the left block expands (left_start_idx decreases), the required
        // right block can only shrink or stay the same.
        int right_end_ptr_c1 = n - 1; // Pointer for condition: max(Right) >= min(Left) - 1
        int right_end_ptr_c2 = n - 1; // Pointer for condition: max(Left) >= min(Right) - 1

        // Iterate through all possible start indices for the left block.
        // The left block is arr[left_start_idx...split_idx].
        for (int left_start_idx = split_idx; left_start_idx >= 0; --left_start_idx)
        {

            // Efficiently update the min/max of the left block in O(1).
            // This was the source of the TLE in the previous version.
            if (left_start_idx == split_idx)
            {
                left_min = arr[left_start_idx];
                left_max = arr[left_start_idx];
            }
            else
            {
                left_min = std::min(left_min, arr[left_start_idx]);
                left_max = std::max(left_max, arr[left_start_idx]);
            }

            // Move the first pointer to find the smallest valid end for the right block
            // that satisfies the first condition.
            while (right_end_ptr_c1 > split_idx + 1 && right_max[right_end_ptr_c1 - 1] >= left_min - 1)
            {
                right_end_ptr_c1--;
            }

            // Move the second pointer for the second condition.
            while (right_end_ptr_c2 > split_idx + 1 && right_min[right_end_ptr_c2 - 1] <= left_max + 1)
            {
                right_end_ptr_c2--;
            }

            // Determine the minimum end index `k` for the right block that satisfies condition 1.
            int min_k_for_c1 = n;
            if (right_end_ptr_c1 >= split_idx + 1 && right_max[right_end_ptr_c1] >= left_min - 1)
            {
                min_k_for_c1 = right_end_ptr_c1;
            }

            // Determine the minimum end index `k` for the right block that satisfies condition 2.
            int min_k_for_c2 = n;
            if (right_end_ptr_c2 >= split_idx + 1 && right_min[right_end_ptr_c2] <= left_max + 1)
            {
                min_k_for_c2 = right_end_ptr_c2;
            }

            // To satisfy BOTH conditions, the right block must extend to the maximum of the two required indices.
            int right_end_idx = std::max(min_k_for_c1, min_k_for_c2);

            // If a valid right block exists...
            if (right_end_idx < n)
            {
                int left_ops = split_idx - left_start_idx;
                int right_ops = right_end_idx - (split_idx + 1);
                min_operations = std::min(min_operations, left_ops + right_ops);
            }
        }
    }

    // If min_operations was never updated, it's impossible.
    // This only occurs when n=2 and the array is not already beautiful.
    if (min_operations == INF)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << min_operations << std::endl;
    }
}

int main()
{
    // Fast I/O
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