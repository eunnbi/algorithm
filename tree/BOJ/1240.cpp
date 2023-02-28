#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> adj[1002];
int dist[1002];
int p[502];
int res[1002][1002];

int main() {
    int n, m, u, v, k;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> k;
        adj[u].push_back({ v, k });
        adj[v].push_back({ u, k });
    }
    for (int i = 1; i <= n; i++) {
        fill(dist + 1, dist + n + 1, -1);
        queue<int> q;
        q.push(i);
        dist[i] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt: adj[cur]) {
                if (dist[nxt.first] != -1) continue;
                dist[nxt.first] = dist[cur] + nxt.second;
                q.push(nxt.first);
            }
        }
        for (int j = 1; j <= n; j++) res[i][j] = dist[j];
    }
    while (m--) {
        cin >> u >> v;
        cout << res[u][v] << '\n';
    }
    return 0;
}
