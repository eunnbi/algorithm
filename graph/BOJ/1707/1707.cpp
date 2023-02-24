#include <iostream>
#include <vector>
#include <queue>
#define NOT_VISITED -1
using namespace std;

vector<int> adj[20002];
int vis[20002];

bool bfs(int start) {
    queue<int> q;
    vis[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt: adj[cur]) {
            if (vis[nxt] == NOT_VISITED) {
                vis[nxt] = 1 - vis[cur];
                q.push(nxt);
            }
            else if (vis[nxt] != (1 - vis[cur])) {
                return false;
            }
        }
    }
    return true;
}

int main()  {
    int k, n, m, u, v;
    cin >> k;
    while (k--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        fill(vis + 1, vis + n + 1, NOT_VISITED);
        string res = "YES\n";
        for (int i = 1; i <= n; i++) {
            if (vis[i] != NOT_VISITED) continue;
            if (!bfs(i)) {
                res = "NO\n";
                break;
            }
        }
        cout << res;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
    }
    return 0;
}