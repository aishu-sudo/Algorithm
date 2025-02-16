#include<bits/stdc++.h>
using namespace std;
#define N 100005

vector<int> graph[N];
bool vis[N];
queue<int> q;
int level[N];

bool bfs(int src) {
    vis[src] = true;
    q.push(src);

    bool flag = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto child: graph[node]) {
            if(vis[child]) {
                if(level[child] != level[node]) {
                    continue;
                } else {
                    flag = false;
                    break;
                }
            }
            q.push(child);
            vis[child] = true;
            level[child] = level[node]+1;
        }
        if(flag == false)
            break;
    }
    return flag;
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
    int res = true;
    for(int i = 1; i <= V; i++) {
        if(vis[i]) {
            continue;
        }
        res &= bfs(i);
    }
    cout << (res != false ? "YES" : "NO") << endl;

    return 0;
}
