#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define V 5

struct Edge
{
    int src, dest, weight;
};

bool compareEdges(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

int findParent(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

void unionSets(int parent[], int x, int y)
{
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    parent[xset] = yset;
}

void kruskalMST(vector<vector<int>> &graph)
{
    vector<Edge> edges;
    for (int i = 0; i < V; ++i)
    {
        for (int j = i + 1; j < V; ++j)
        {
            if (graph[i][j] != 0)
            {
                Edge edge;
                edge.src = i;
                edge.dest = j;
                edge.weight = graph[i][j];
                edges.push_back(edge);
            }
        }
    }
    cout << "given edges: ";
    for (const Edge &edge : edges)
    {
        cout << "(" << edge.src << "," << edge.dest << "," << edge.weight << ")  ";
    }

    cout << endl;
    sort(edges.begin(), edges.end(), compareEdges);
    cout << "after sorting edges: ";
    for (const Edge &edge : edges)
    {
        cout << "(" << edge.src << "," << edge.dest << "," << edge.weight << ")  ";
    }
    cout << endl;
    vector<Edge> result;
    int parent[V];
    for (int i = 0; i < V; ++i)
        parent[i] = -1;

    int edgeCount = 0;
    for (const Edge &edge : edges)
    {
        int x = findParent(parent, edge.src);
        int y = findParent(parent, edge.dest);
        cout << "curent node of consideration:"
             << "(" << edge.src << "," << edge.dest << "," << edge.weight << ")   ";
        if (x != y)
        {
            cout << "result:takent into mst" << endl;
            result.push_back(edge);
            unionSets(parent, x, y);
            ++edgeCount;
        }
        else
            cout << "result:not takent into mst because of cycle formation" << endl;

        if (edgeCount == V - 1)
            break;
    }

    // cout << "Edge \tWeight" << endl;
    int totalCost=0;
    for (const Edge &edge : result)
    {
        cout << edge.src << " - " << edge.dest << "\t";
        //  << edge.weight << endl;
        totalCost+=edge.weight;
    }
    cout<<"Total cost for mst : "<<totalCost;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    kruskalMST(graph);

    return 0;
}
