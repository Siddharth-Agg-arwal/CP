class Solution
{
public:
    bool static comparator(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] != b[0])
        {
            return a[0] > b[0];
        }
        else if (a[1] != b[1])
        {
            return a[1] > b[1];
        }
        return a[2] > b[2];
        // return a[2] > b[2];
    }
    int maxHeight(vector<vector<int>> &cuboids)
    {
        // int max_height = 0;

        int n = cuboids.size();
        for (int i = 0; i < n; i++)
        {
            sort(cuboids[i].begin(), cuboids[i].end());
            // max_height = max(max_height, cuboids[i][2]);
        }

        sort(cuboids.begin(), cuboids.end(), comparator);
        vector<int> dp(n);
        int max_h = 1;
        for (int i = 0; i < n; i++)
        {
            dp[i] = cuboids[i][2];
            for (int j = 0; j < i; j++)
            {
                if (cuboids[j][0] >= cuboids[i][0] && cuboids[j][1] >= cuboids[i][1] && cuboids[j][2] >= cuboids[i][2])
                {
                    dp[i] = max(dp[i], cuboids[i][2] + dp[j]);
                }
                // else if(cuboids[j][1] >= cuboids[i][0] && cuboids[j][0] >= cuboids[i][1] && cuboids[j][2] >= cuboids[i][2]){
                //     dp[i] = max(dp[i], cuboids[i][2] + cuboids[j][2]);
                // }
            }

            max_h = max(max_h, dp[i]);
        }

        return max_h;
    }
};