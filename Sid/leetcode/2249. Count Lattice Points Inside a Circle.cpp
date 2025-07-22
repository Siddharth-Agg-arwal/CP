class Solution
{
public:
    int countLatticePoints(vector<vector<int>> &circles)
    {
        set<pair<int, int>> points;

        for (int i = 0; i < circles.size(); i++)
        {
            int cx = circles[i][0];
            int cy = circles[i][1];
            int r = circles[i][2];

            for (int j = cx - r; j <= cx + r; j++)
            {
                int cy_max = sqrt((r * r) - ((j - cx) * (j - cx)));
                int cy_min = (-1) * cy_max;
                for (int k = cy - cy_max; k <= cy + cy_max; k++)
                {
                    points.insert({j, k});
                }
            }
        }

        return points.size();
    }
};