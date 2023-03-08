#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> adj[10002];
int dist[10002];
int res;
void dfs(int cur) {
    for (auto nxt: adj[cur]) {
        if (dist[nxt.first] != -1) continue;
        dist[nxt.first] = dist[cur] + nxt.second;
        res = max(res, dist[nxt.first]);
        dfs(nxt.first);
    }
}
int main() {
    int n, u, v, w;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    for (int i = 1; i <= n; i++) {
        fill(dist + 1, dist + 1 + n, -1);
        dist[i] = 0;
        dfs(i);
    }
    cout << res;
    return 0;
}