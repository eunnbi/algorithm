#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[502];
int dist[502];
int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(dist, dist + n + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt: adj[cur]) {
            if (dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 1 || dist[i] == 2) res++;
    }
    cout << res;
    return 0;
}