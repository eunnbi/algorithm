#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[502];
bool vis[502];
int p[502];
bool isTree;

void dfs(int cur) {
    vis[cur] = true;
    for (int nxt: adj[cur]) {
        if (p[cur] == nxt) continue;
        if (vis[nxt]) {
            isTree = false;
            continue;
        }
        p[nxt] = cur;
        dfs(nxt);
    }
}

int main() {
    int n, m, u, v;
    int tc = 0;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res = 0;
        fill(vis + 1, vis + n + 1, false);
        fill(p + 1, p + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            isTree = true;
            dfs(i);
            res += isTree;
        }
        cout << "Case " << ++tc << ": ";
        if (res == 0) cout << "No trees.\n";
        else if (res == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << res << " trees.\n";
    }
    return 0;
}