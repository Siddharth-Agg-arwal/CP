#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests--)
    {
        int total_pos, start_pos;
        cin >> total_pos >> start_pos;

        vector<int> positions(total_pos);
        for (int i = 0; i < total_pos; i++)
        {
            cin >> positions[i];
        }

        auto it = lower_bound(positions.begin(), positions.end(), start_pos);
        int start_idx = int(it - positions.begin());
        positions.insert(it, start_pos);

        long long moves_left = 0, moves_right = 0;
        for (int i = 0; i + 1 < positions.size(); ++i)
        {
            int dist = positions[i + 1] - positions[i];
            if (i < start_idx)
                moves_left += dist;
            else
                moves_right += dist;
        }

        long long ans = min(moves_left, moves_right) * 2 + max(moves_left, moves_right);
        cout << ans << "\n";
    }

    return 0;
}
