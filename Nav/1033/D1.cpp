#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <climits>
#include <cassert>
using namespace std;

// Type alias for edge representation
using Edge = pair<int, int>;

// Reads an integer
int readInt()
{
    int value;
    cin >> value;
    return value;
}

// Reads an undirected edge into the adjacency list
void addEdge(vector<vector<int>> &graph, int node1, int node2)
{
    graph[node1].push_back(node2);
    graph[node2].push_back(node1);
}

// Finds a node with degree 2, which is considered the center
int findCenterNode(const vector<vector<int>> &graph)
{
    for (int node = 1; node < graph.size(); ++node)
    {
        if (graph[node].size() == 2)
        {
            return node;
        }
    }
    return -1;
}

// Adds edges from subtree rooted at startNode, alternating direction
void exploreSubtree(
    const vector<vector<int>> &graph,
    int currentNode,
    int parent,
    int depth,
    int centerNode,
    int avoidNode,
    vector<Edge> &resultEdges,
    bool reverseDirection)
{
    for (int neighbor : graph[currentNode])
    {
        if (neighbor == parent || (currentNode == avoidNode && neighbor == centerNode) || (currentNode == centerNode && neighbor == avoidNode))
        {
            continue;
        }
        if ((depth % 2 == 0) ^ reverseDirection)
            resultEdges.emplace_back(currentNode, neighbor);
        else
            resultEdges.emplace_back(neighbor, currentNode);

        exploreSubtree(graph, neighbor, currentNode, depth + 1, centerNode, avoidNode, resultEdges, reverseDirection);
    }
}

// Processes a single test case
void solveTestCase()
{
    int numberOfNodes = readInt();
    vector<vector<int>> graph(numberOfNodes + 1);

    for (int i = 1; i < numberOfNodes; ++i)
    {
        int nodeA = readInt();
        int nodeB = readInt();
        addEdge(graph, nodeA, nodeB);
    }

    if (numberOfNodes == 2)
    {
        cout << "NO\n";
        return;
    }

    int centerNode = findCenterNode(graph);
    if (centerNode == -1)
    {
        cout << "NO\n";
        return;
    }

    int leftChild = graph[centerNode][0];
    int rightChild = graph[centerNode][1];

    cout << "YES\n";
    vector<Edge> resultEdges;
    resultEdges.emplace_back(leftChild, centerNode);
    resultEdges.emplace_back(centerNode, rightChild);

    exploreSubtree(graph, leftChild, centerNode, 0, centerNode, rightChild, resultEdges, false);
    exploreSubtree(graph, rightChild, centerNode, 0, centerNode, leftChild, resultEdges, true);

    for (const Edge &edge : resultEdges)
    {
        cout << edge.second << " " << edge.first << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases = readInt();
    while (testCases--)
    {
        solveTestCase();
    }

    return 0;
}
