#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[20002];
int dist[20002];
int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    fill(dist + 1, dist + n + 1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt: adj[cur]) {
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    
    int num = 0;
    int mx = -1;
    int res;
    for (int i = 1; i <= n; i++) {
        if (mx < dist[i]) {
            mx = dist[i];
            res = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (mx == dist[i]) num++;
    }
    cout << res << ' ' << mx << ' ' << num;
    return 0;
}