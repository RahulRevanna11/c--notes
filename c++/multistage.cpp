#include <iostream>
#include <climits>
#include <vector>

using namespace std;

const int INF = INT_MAX;

int main() {
    // Example multistage graph representation
    vector<vector<int>> graph = {
        {INF, 1, 2, 5, INF, INF, INF},
        {INF, INF, INF, INF, 4, 11, INF},
        {INF, INF, INF, INF, 9, 5, 16},
        {INF, INF, INF, INF, INF, INF, 2},
        {INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF}
    };

    int stages = graph.size();

    // Cost array to store the minimum cost to reach each stage
    vector<int> cost(stages, INF);

    // Initialize the cost for the last stage
    cost[stages - 1] = 0;

    // Dynamic programming to calculate the minimum cost for each stage
    for (int i = stages - 2; i >= 0; --i) {
        for (int j = 0; j < stages; ++j) {
            if (graph[i][j] != INF) {
                cost[i] = min(cost[i], graph[i][j] + cost[j]);
            }
        }
    }

    // Print the minimum cost to reach the first stage
    cout << "Minimum cost to reach the first stage: " << cost[0] << endl;

    return 0;
}

