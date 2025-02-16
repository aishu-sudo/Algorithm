#include <bits/stdc++.h>
using namespace std;

queue<int> q;
const int INF = INT_MAX;
int dist[100];

int main() {
    int n, m; // Number of nodes and edges
    cin >> n >> m;

    int graph[100][100]; // Adjacency matrix

    // Initialize adjacency matrix with INF (except diagonal elements)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w; // Directed graph
    }

    int source;
    cin >> source;

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF) { // Check if edge exists
                int w = graph[u][v];

                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    q.push(v);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            cout << "Unreachable\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
