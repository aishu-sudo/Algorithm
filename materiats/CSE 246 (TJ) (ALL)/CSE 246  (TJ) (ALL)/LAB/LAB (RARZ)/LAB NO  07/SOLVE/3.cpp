#include<bits/stdc++.h>
using namespace std;
#define n 1009

vector<int> graph[n];
int vis[n];
int depth[n];

int dfs(int vertex) {
    static int max = vertex;
    vis[vertex] = true;
    for(auto child: graph[vertex]) {
        if(vis[child]) {
            continue;
        }
        depth[child] = depth[vertex]+1;
        if(depth[child] > depth[max])
            max = child;
        dfs(child);
    }
    return max;
}

int main() {
    int V, E;
    cin >> V >> E;

    for(int i = 1; i <= E; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int r1 = dfs(1);
    memset(vis, 0, sizeof(vis));
    memset(depth, 0, sizeof(depth));
    int r2 = dfs(r1);

    cout << depth[r2] << endl;

    return 0;
}
