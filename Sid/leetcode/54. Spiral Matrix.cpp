#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int top = 0, left = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1;
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> ans;
        int size_ans = 0;

        while (size_ans < rows * cols)
        {

            if (top <= bottom)
            {
                for (int i = left; i <= right; i++)
                {
                    ans.push_back(matrix[top][i]);
                    size_ans += 1;
                    // cout << top << "," << i << " ";
                }
                top += 1;
            }
            // cout << endl;

            if (left <= right)
            {
                for (int i = top; i <= bottom; i++)
                {
                    ans.push_back(matrix[i][right]);
                    size_ans += 1;
                    // cout << i << "," << right << " ";
                }
                right -= 1;
            }
            // cout << endl;

            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                    size_ans += 1;
                    // cout << bottom << "," << i << " ";
                }
                bottom -= 1;
            }
            // cout << endl;

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                    size_ans += 1;
                    // cout << left << "," << i << " ";
                }

                left += 1;
            }
            // cout << endl;
        }

        return ans;
    }
};