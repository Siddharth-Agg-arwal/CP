using System;
using System.Collections.Generic;
using System.Linq;

class MaximumBipartiteMatching
{
    private List<int>[] adjacencyList;
    private int[] pairX, pairY, levels;
    private int numVerticesX, numVerticesY;

    public MaximumBipartiteMatching(int numVerticesX, int numVerticesY)
    {
        this.numVerticesX = numVerticesX;
        this.numVerticesY = numVerticesY;
        adjacencyList = new List<int>[numVerticesX];
        for (int i = 0; i < numVerticesX; i++) adjacencyList[i] = new List<int>();
        pairX = new int[numVerticesX];
        pairY = new int[numVerticesY];
        levels = new int[numVerticesX];
        Array.Fill(pairX, -1);
        Array.Fill(pairY, -1);
    }

    public void AddEdge(int x, int y)
    {
        adjacencyList[x].Add(y);
    }

    private bool PerformBfs()
    {
        Array.Fill(levels, -1);
        Queue<int> queue = new Queue<int>();
        for (int x = 0; x < numVerticesX; x++)
        {
            if (pairX[x] == -1)
            {
                levels[x] = 0;
                queue.Enqueue(x);
            }
        }
        bool foundMatch = false;
        while (queue.Count > 0)
        {
            int x = queue.Dequeue();
            foreach (int y in adjacencyList[x])
            {
                if (pairY[y] == -1)
                {
                    foundMatch = true;
                }
                else if (levels[pairY[y]] == -1)
                {
                    levels[pairY[y]] = levels[x] + 1;
                    queue.Enqueue(pairY[y]);
                }
            }
        }
        return foundMatch;
    }

    private bool PerformDfs(int x)
    {
        foreach (int y in adjacencyList[x])
        {
            if (pairY[y] == -1 || (levels[pairY[y]] == levels[x] + 1 && PerformDfs(pairY[y])))
            {
                pairX[x] = y;
                pairY[y] = x;
                return true;
            }
        }
        levels[x] = -1;
        return false;
    }

    public int FindMaximumMatching()
    {
        int matchCount = 0;
        while (PerformBfs())
        {
            for (int x = 0; x < numVerticesX; x++)
            {
                if (pairX[x] == -1 && PerformDfs(x))
                {
                    matchCount++;
                }
            }
        }
        return matchCount;
    }
}

class Program
{
    static void Main(string[] args)
    {
        int testCaseCount = int.Parse(Console.ReadLine());
        while (testCaseCount-- > 0)
        {
            int n = int.Parse(Console.ReadLine());
            int[][] matrix = new int[n][];
            for (int i = 0; i < n; i++)
            {
                matrix[i] = Console.ReadLine().Split().Select(int.Parse).ToArray();
            }

            int[][] prefixSum = new int[n][];
            for (int i = 0; i < n; i++)
            {
                prefixSum[i] = new int[n + 1];
                prefixSum[i][0] = 0;
                for (int j = 1; j <= n; j++)
                {
                    prefixSum[i][j] = prefixSum[i][j - 1] + matrix[i][n - j];
                }
            }

            List<List<int>> verticesQueues = new List<List<int>>();
            for (int i = 0; i <= n; i++)
            {
                verticesQueues.Add(new List<int>());
            }

            bool[] isPossible = new bool[n + 1];
            for (int i = 0; i <= n; i++)
            {
                isPossible[i] = false;
                for (int j = 0; j < n; j++)
                {
                    if (prefixSum[j][i] == i)
                    {
                        verticesQueues[i].Add(j);
                        isPossible[i] = true;
                    }
                }
            }

            int maxMatching = 0;
            for (int m = n; m >= 0; m--)
            {
                if (m == 0)
                {
                    maxMatching = 0;
                    break;
                }

                bool isValid = true;
                for (int i = 0; i < m; i++)
                {
                    if (i > n || !isPossible[i])
                    {
                        isValid = false;
                        break;
                    }
                }
                if (!isValid) continue;

                MaximumBipartiteMatching bipartiteMatcher = new MaximumBipartiteMatching(m, n);
                for (int i = 0; i < m; i++)
                {
                    List<int> currentQueue = verticesQueues[i];
                    foreach (int vertex in currentQueue)
                    {
                        bipartiteMatcher.AddEdge(i, vertex);
                    }
                }

                int currentMatch = bipartiteMatcher.FindMaximumMatching();
                if (currentMatch == m)
                {
                    maxMatching = m;
                    break;
                }
            }

            Console.WriteLine(maxMatching);
        }
    }
}
