#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100002];
bool vis[100002];

void dfs(int cur) {
    vis[cur] = true;
    for (int nxt: adj[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int groupCnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i);
        groupCnt++;
    }
    cout << (groupCnt - 1) + (m + groupCnt - 1) - (n - 1);
    return 0;
}