#include <bits/stdc++.h>
using namespace std;

int minKey(vector<int> &key, vector<bool> &inMST, int V) {
    int minVal = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < minVal) {
            minVal = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(vector<vector<int>> &graph, int V) {
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, inMST, V);
        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Edges in MST:\n";
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " (weight " << graph[i][parent[i]] << ")\n";
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total Weight = " << totalWeight << "\n";
}

int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph, V);

    return 0;
}
