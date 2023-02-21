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
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        res++;
        q.push(i);
        vis[i] = true;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt: adj[cur]) {
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    cout << res;
    return 0;
}
