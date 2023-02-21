#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[1002];
bool vis[1002];
int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    int res = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        res++;
        for (int nxt: adj[cur]) {
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
    cout << res - 1;
    return 0;
}
