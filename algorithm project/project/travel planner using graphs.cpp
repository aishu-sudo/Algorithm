#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int distance;
    int time;
    int cost;
};

int dist[100];
int parent[100];

void calculateShortestPaths(int n, Edge matrix[100][100], int source, string criteria) {
    bool visited[100] = {false};

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[source] = 0;

    for (int i = 0; i < n; i++) {

        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }


        visited[u] = true;


        for (int v = 0; v < n; v++) {
            bool edgeExists = false;
            int weight = 0;

            if (criteria == "distance") {
                edgeExists = (matrix[u][v].distance != INF);
                weight = matrix[u][v].distance;
            } else if (criteria == "time") {
                edgeExists = (matrix[u][v].time != INF);
                weight = matrix[u][v].time;
            } else if (criteria == "cost") {
                edgeExists = (matrix[u][v].cost != INF);
                weight = matrix[u][v].cost;
            }

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }
}

vector<int> createPath(int destination) {
    vector<int> path;
    for (int v = destination; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n = 5;
    int m = 6;

    Edge matrix[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = {0, 0, 0};
            } else {
                matrix[i][j] = {INF, INF, INF};
            }
        }
    }

    matrix[0][1] = {10, 5, 20};
    matrix[0][4] = {5, 3, 15};
    matrix[1][2] = {1, 2, 10};
    matrix[2][3] = {4, 4, 25};
    matrix[4][1] = {3, 1, 5};
    matrix[4][3] = {2, 2, 30};

    int source, destination;
    cout << "Enter starting node: ";
    cin >> source;
    cout << "Enter destination node: ";
    cin >> destination;

    calculateShortestPaths(n, matrix, source, "distance");

    if (dist[destination] == INF) {
        cout << "Destination node " << destination << " is unreachable from node " << source << ".\n";
        return 0;
    }

    vector<int> path = createPath(destination);

    int totalTime = 0, totalCost = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        int u = path[i], v = path[i + 1];
        totalTime += matrix[u][v].time;
        totalCost += matrix[u][v].cost;
    }

    cout << "\nOptimal Path: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1)
        {
            cout<< "->" ;
        }
    }
    cout << "\nTotal Distance: " << dist[destination] << "\n";
    cout << "Total Time: " << totalTime << "\n";
    cout << "Total Cost: " << totalCost << "\n";

}
