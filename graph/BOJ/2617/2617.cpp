#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> heavy[102];
vector<int> light[102];
bool vis[102];
int bfs(vector<int> adj[], int start) {
    queue<int> q;
    vis[start] = true;
    q.push(start);
    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt: adj[cur]) {
            if (vis[nxt]) continue;
            cnt++;
            vis[nxt] = true;
            q.push(nxt);
        }
    }
    return cnt;
}
int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        light[u].push_back(v);
        heavy[v].push_back(u);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        fill(vis + 1, vis + n + 1, false);
        int big = bfs(heavy, i);
        int small = bfs(light, i);
        if (big > ((n - 1) / 2) || small > ((n - 1) / 2)) res++;
    }
    cout << res;
    return 0;
}