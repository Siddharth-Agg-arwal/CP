#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Function to simulate the game and calculate the score for a given hand.
// This function is O(n).
int calculate_score(int n, const std::vector<int> &a, const std::vector<int> &b)
{
    int p_ptr = 0;
    int d_ptr = 0;
    // The game lasts for exactly n rounds.
    for (int round = 0; round < n; ++round)
    {
        // Pointers can't exceed n, but this check is good practice.
        if (p_ptr >= n || d_ptr >= n)
        {
            break;
        }
        if (a[p_ptr] > b[d_ptr])
        {
            p_ptr++; // Player wins, advance player's card pointer.
        }
        else
        {
            d_ptr++; // Dealer wins, advance dealer's card pointer.
        }
    }
    return p_ptr; // The score is the final player pointer.
}

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < n; ++i)
        std::cin >> b[i];

    // 1. Calculate the score with the original hand (no swaps).
    int max_score = calculate_score(n, a, b);

    // 2. Brute-force all possible single swaps.
    // This is O(n^2) pairs, and each check is O(n), so total is O(n^3).
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            // Perform the swap.
            std::swap(a[i], a[j]);

            // Calculate the score with the swapped hand and update max_score.
            max_score = std::max(max_score, calculate_score(n, a, b));

            // Swap back to restore the original array for the next iteration.
            std::swap(a[i], a[j]);
        }
    }

    std::cout << max_score << std::endl;
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