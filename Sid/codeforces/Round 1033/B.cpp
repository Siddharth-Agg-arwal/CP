#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int num_balls = 0, table_len = 0;
        cin >> num_balls >> table_len;

        vector<vector<int>> speed_coords(num_balls, vector<int>(4, 0));
        for (int i = 0; i < num_balls; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> speed_coords[i][j];
            }
        }

        set<vector<int>> pocket_coords;
        pocket_coords.insert({0, 0});
        pocket_coords.insert({0, table_len});
        pocket_coords.insert({table_len, 0});
        pocket_coords.insert({table_len, table_len});

        vector<vector<int>> start_coords(num_balls, vector<int>(2, 0));
        for (int i = 0; i < num_balls; i++)
        {
            start_coords[i][0] = speed_coords[i][2];
            start_coords[i][1] = speed_coords[i][3];
        }

        int balls_pocketed = 0;
        map<vector<int>, int> curr_coords;
        while (1)
        {

            for (int i = 0; i < num_balls; i++)
            {
                int new_x = speed_coords[i][2] + speed_coords[i][0] / 2;
                int new_y = speed_coords[i][3] + speed_coords[i][1] / 2;

                if (pocket_coords.find({new_x, new_y}) != pocket_coords.end())
                {
                    balls_pocketed += 1;
                    continue;
                }
                if (curr_coords.find({new_x, new_y}) != curr_coords.end())
                {
                    int ball1 = curr_coords[{new_x, new_y}];
                    int ball2 = i;
                    speed_coords[ball1][0] = speed_coords[ball1][0] * (-1);
                    speed_coords[ball1][1] = speed_coords[ball1][1] * (-1);
                    speed_coords[ball2][0] = speed_coords[ball2][0] * (-1);
                    speed_coords[ball2][1] = speed_coords[ball2][1] * (-1);
                }
                else
                {
                    curr_coords[{new_x, new_y}] = i;
                }

                if (new_x == 0 || new_y == table_len || new_y == 0 || new_x == table_len)
                {
                }

                speed_coords[i][2] = new_x;
                speed_coords[i][3] = new_y;
            }

            for (int i = 0; i < num_balls; i++)
            {
                start_coords[i][0] = speed_coords[i][2];
                start_coords[i][1] = speed_coords[i][3];
                break;
            }
        }
    }
}