#include <iostream>
#include <vector>
#include <numeric>

using int128 = __int128_t;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--)
    {
        long long n;
        long long px, py, qx, qy;
        cin >> n >> px >> py >> qx >> qy;

        vector<long long> lens(n);
        long long total_len = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> lens[i];
            total_len += lens[i];
        }

        if (px == qx && py == qy)
        {
            bool all_equal = true;
            for (int i = 1; i < n; i++)
            {
                if (lens[i] != lens[0])
                {
                    all_equal = false;
                    break;
                }
            }
            if (all_equal)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
            continue;
        }

        long long dx = qx - px;
        long long dy = qy - py;

        int128 min_dist_sq = (int128)dx * dx + (int128)dy * dy;

        if ((int128)total_len * total_len >= min_dist_sq)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
