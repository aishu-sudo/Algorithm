#include<bits/stdc++.h>
using namespace std;
#define N 100005

vector<int> graph[N];
bool vis[N];
queue<int> q;
int level[N];

void bfs(int src, int des) {
    vis[src] = true;
    q.push(src);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto child: graph[node]) {
            if(vis[child]) {
                continue;
            }
            q.push(child);
            vis[child] = true;
            level[child] = level[node]+1;
        }
    }

    if(level[des] != 0)
        cout << level[des] << endl;
    else
        cout << "INF" << endl;
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
    int S, D;
    cin >> S >> D;
    bfs(S, D);

    return 0;
}
