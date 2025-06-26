#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int st = 0;
        int ed = matrix.size() - 1;

        while (st <= ed)
        {
            int mid = (st + ed) / 2;

            if (target < matrix[mid][0])
            {
                ed = mid - 1;
            }
            else if (target > matrix[mid][matrix[0].size() - 1])
            {
                st = mid + 1;
            }
            else
            {
                st = mid;
                break;
            }

            // cout << mid << " ";
        }

        if (st < 0 || st >= matrix.size())
            return false;
        int row = st;
        // else row = 0;
        // cout << row << " ";
        st = 0;
        ed = matrix[0].size() - 1;

        while (st <= ed)
        {
            int mid = (st + ed) / 2;
            if (matrix[row][mid] == target)
            {
                return true;
            }
            if (matrix[row][mid] < target)
            {
                st = mid + 1;
            }
            else
            {
                ed = mid - 1;
            }
            // cout << st << " " << ed << "\n";
        }

        return false;
    }
};