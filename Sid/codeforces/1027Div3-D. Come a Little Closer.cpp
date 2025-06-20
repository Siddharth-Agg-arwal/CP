//incomplete

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int monsters;
        cin >> monsters;
        set<vector<int>> monster_loc;

        vector<vector<int>> monster_pos(monsters, vector<int>(2, 0));
        for (int i = 0; i < monsters; i++)
        {
            cin >> monster_pos[i][0] >> monster_pos[i][1];
            monster_loc.insert({monster_pos[i][0], monster_pos[i][1]});
        }

        // vector<int> areas(monsters, 0);
        int min_area = 1e9, min_area_idx = -1;
        int x_min = 1e9, x_max = -1e9, y_min = 1e9, y_max = -1e9;

        for (int i = 0; i < monsters; i++)
        {
            int xmin = 1e9, xmax = -1e9, ymin = 1e9, ymax = -1e9;
            int curr_area = 0;
            for (int j = 0; j < monsters; j++)
            {
                if (j != i)
                {
                    xmin = min(xmin, monster_pos[j][0]);
                    xmax = max(xmax, monster_pos[j][0]);
                    ymin = min(ymin, monster_pos[j][1]);
                    ymax = max(ymax, monster_pos[j][1]);
                }
            }

            curr_area = (xmax - xmin) * (ymax - ymin);
            // cout << curr_area << " ";
            if (curr_area < min_area)
            {
                min_area = curr_area;
                min_area_idx = i;
                x_min = min(x_min, xmin);
                y_min = min(y_min, ymin);
                x_max = max(x_max, xmax);
                y_max = max(y_max, ymax);
            }

            // cout << min_area << " ";
        }

        int xmin = x_min, xmax = x_max, ymin = y_min, ymax = y_max;
        int min_val = 1e9;
        for (int i = x_min; i < x_max + 2; i++)
        {
            for (int j = y_min; j < y_max + 2; j++)
            {
                if (monster_loc.find({i, j}) != monster_loc.end())
                {
                    continue;
                }
                xmin = min(xmin, i);
                xmax = max(xmax, i);
                ymin = min(ymin, j);
                ymax = max(ymax, j);
                int curr_area = (xmax - xmin) * (ymax - ymin);
                min_val = min(curr_area, min_val);
            }
        }

        cout << min_val << endl;
    }

    return 0;
}