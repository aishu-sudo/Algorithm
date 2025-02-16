#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
queue<int> q;
int col[100], par[100], d[100];

void bfs() {
    vector<int> traversal; // To store the BFS traversal

    while (!q.empty()) {

        int u = q.front();
        q.pop();
        traversal.push_back(u); // Add the current node to the traversal list

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (col[v] == 0) {
                col[v] = 1;
                d[v] = d[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
        col[u] = 2;

        // Display visited status after processing the current node
        //printf("Visited: ");
        /*for (int i = 0; i < 100; i++) {
            if (col[i] != 0) {
                printf("true ");
            } else {
                printf("false ");
            }
        }
        printf("\n");*/
    }

    // Print the final BFS traversal
    printf("BFS Traversal: ");
    for (int node : traversal) {
        printf("%d ", node);
    }
    printf("\n");
}

int main() {
    int n, edge;
    scanf("%d%d", &n, &edge);

    for (int i = 0; i < edge; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        col[i] = 0;
        d[i] = 9999;
        par[i] = -1;
    }

    int src;
    printf("source: ");
    scanf("%d", &src);

    col[src] = 1;
    d[src] = 0;
    q.push(src);

    bfs();

    return 0;
}
