#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &weight_matrix, int num_vertices)
{

    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            if (weight_matrix[i][j] == -1)
                weight_matrix[i][j] = 1e9;
            if (i == j)
                weight_matrix[i][j] = 0;
        }
    }

    for (int k = 0; k < num_vertices; k++)
    {
        for (int i = 0; i < num_vertices; i++)
        {
            for (int j = 0; j < num_vertices; j++)
            {
                weight_matrix[i][j] = min(weight_matrix[i][j], weight_matrix[i][k] + weight_matrix[k][j]);
            }
        }
    }

    // check for negative cycle
    for (int i = 0; i < num_vertices; i++)
    {
        if (weight_matrix[i][i] < 0)
            cout << "negative cycle exists.";
    }

    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            if (weight_matrix[i][j] == 1e9)
                weight_matrix[i][j] = -1;
        }
    }
}

int main()
{
    int num_vertices = 4;
    vector<vector<int>> weight_matrix = {{0, 1, 43, -1},
                                         {1, 0, 6, 2},
                                         {-1, -1, 0, 2},
                                         {2, 3, 4, 0}};
    floydWarshall(weight_matrix, num_vertices);

    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            cout << weight_matrix[i][j] << " ";
        }
        cout << endl;
    }
}