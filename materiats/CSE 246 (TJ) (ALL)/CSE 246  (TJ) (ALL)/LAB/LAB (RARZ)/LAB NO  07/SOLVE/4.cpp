#include<bits/stdc++.h>
using namespace std;
#define N 100005

vector<int> graph[N];
bool vis[N];
queue<int> q;
int level[N];

void bfs(int src) {
    vis[src] = true;
    int flag = 0;
    q.push(src);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto child: graph[node]) {
            if(vis[child]) {
                if(level[child] > level[node]) {
                    flag = 1;
                    break;
                }
                continue;
            }
            q.push(child);
            vis[child] = true;
            level[child] = level[node]+1;
        }
        if(flag == 1)
            break;
    }
    cout << (flag != 0 ? "YES" : "NO") << endl;
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
    int S;
    cin >> S;
    bfs(S);

    return 0;
}
