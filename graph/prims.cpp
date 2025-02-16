#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;
const int N = 5;

int graph[N][N] = {
    {0, 2, INF, 6, INF},
    {2, 0, 3, 8, 5},
    {INF, 3, 0, INF, 7},
    {6, 8, INF, 0, 9},
    {INF, 5, 7, 9, 0}
};


int minKey(int key[], bool mstSet[]) {
    int min = INF, minIndex;

    for (int v = 0; v < N; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v], minIndex = v;
        }
    }
    return minIndex;
}


void primMST() {
    int parent[N];
    int key[N];
    bool mstSet[N];


    for (int i = 0; i < N; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }


    key[0] = 0;
    parent[0] = -1;


    for (int count = 0; count < N - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;


        for (int v = 0; v < N; v++) {
            if (graph[u][v] && graph[u][v] != INF && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }


    cout << "Edge   Weight\n";
    for (int i = 1; i < N; i++) {
        cout << parent[i] << " - " << i << "   " << graph[i][parent[i]] << "\n";
    }
}


int main() {
    primMST();
    return 0;
}

