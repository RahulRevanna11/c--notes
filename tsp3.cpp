#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = numeric_limits<int>::max();

class Node {
public:
    int level;
    int bound;
    vector<int> path;

    Node(int l, int b, vector<int> p) : level(l), bound(b), path(move(p)) {}
};

class CompareNode {
public:
    bool operator()(const Node& a, const Node& b) {
        return a.bound > b.bound;
    }
};

int tsp_bunch_and_bound(const vector<vector<int>>& graph) {
    int n = graph.size();

    // Priority queue for the nodes
    priority_queue<Node, vector<Node>, CompareNode> pq;

    // Initialize a root node
    Node root(0, 0, {0});

    // Initialize the best cost to infinity
    int best_cost = INF;

    // Calculate the initial bound for the root node
    root.bound = 0;
    for (int i = 0; i < n; ++i) {
        int min1 = INF, min2 = INF;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (graph[i][j] < min1) {
                    min2 = min1;
                    min1 = graph[i][j];
                } else if (graph[i][j] < min2) {
                    min2 = graph[i][j];
                }
            }
        }
        root.bound += (min1 + min2);
    }

    // Add the root node to the priority queue
    pq.push(root);

    // Branch and bound algorithm
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.bound < best_cost) {
            if (current.level == n - 1) {
                // If the node is a leaf, update the best cost
                best_cost = min(best_cost, current.bound);
            } else {
                // Generate child nodes and add them to the priority queue
                for (int i = 0; i < n; ++i) {
                    if (find(current.path.begin(), current.path.end(), i) == current.path.end()) {
                        // Calculate the cost for the child node
                        int cost = current.bound - (current.path.size() == 1 ? 0 : graph[current.path[current.level - 1]][i]);
                        cost += graph[current.path.back()][i];

                        // Create the child node
                        Node child(current.level + 1, cost, current.path);
                        child.path.push_back(i);

                        // Update the bound for the child node
                        int min1 = INF, min2 = INF;
                        for (int j = 0; j < n; ++j) {
                            if (i != j) {
                                if (graph[i][j] < min1) {
                                    min2 = min1;
                                    min1 = graph[i][j];
                                } else if (graph[i][j] < min2) {
                                    min2 = graph[i][j];
                                }
                            }
                        }
                        child.bound += (min1 + min2);

                        // Add the child node to the priority queue
                        pq.push(child);
                    }
                }
            }
        }
    }

    return best_cost;
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int result = tsp_bunch_and_bound(graph);

    cout << "Minimum cost of TSP tour: " << result << endl;

    return 0;
}

