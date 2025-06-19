#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        int top = 0, left = 0;

        while (top <= rows - 1)
        {
            for (int k = top; k < rows; k++)
            {
                int temp = matrix[top][k];
                matrix[top][k] = matrix[k][left];
                matrix[k][left] = temp;
            }
            left += 1;
            top += 1;
        }

        for (int i = 0; i < rows; i++)
        {
            int rptr = 0, lptr = rows - 1;
            while (rptr < lptr)
            {
                int temp = matrix[i][rptr];
                matrix[i][rptr] = matrix[i][lptr];
                matrix[i][lptr] = temp;
                rptr += 1;
                lptr -= 1;
            }
        }
    }
};