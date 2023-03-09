#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> adj[100002];
int dist[100002];
int maxNode, res;
void dfs(int cur) {
    for (auto nxt: adj[cur]) {
        if (dist[nxt.first] != -1) continue;
        dist[nxt.first] = dist[cur] + nxt.second;
        if (dist[nxt.first] > res) {
            res = dist[nxt.first];
            maxNode = nxt.first;
        }
        dfs(nxt.first);
    }
}
int main() {
    int n, u, v, w;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> u;
        while (true) {
            cin >> v;
            if (v == -1) break;
            cin >> w;
            adj[u].push_back({ v, w });
            adj[v].push_back({ u, w });
        }
    }
    fill(dist + 1, dist + 1 + n, -1);
    dist[1] = 0;
    dfs(1);
    fill(dist + 1, dist + 1 + n, -1);
    dist[maxNode] = 0;
    dfs(maxNode);
    cout << res;
    return 0;
}