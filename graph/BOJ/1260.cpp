#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[1002];
bool vis[1002];
void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for (int nxt: adj[cur]) {
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}
void dfs(int cur) {
    vis[cur] = true;
    cout << cur << ' ';
    for (int nxt: adj[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}
int main() {
    int n, m, k, u, v;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(k);
    cout << '\n';
    fill(vis, vis + 1002, false);
    bfs(k);
    return 0;
}