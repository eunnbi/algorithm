#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[10002];
bool vis[10002];
int res[10002];
int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[v].push_back(u);
    }
    
    int num = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        fill(vis + 1, vis + n + 1, false);
        q.push(i);
        vis[i] = true;
        num = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nxt: adj[cur]) {
                if (vis[nxt]) continue;
                vis[nxt] = true;
                q.push(nxt);
                num++;
            }
        }
        res[i] = num;
    }
    int mx = *max_element(res + 1, res + n + 1);
    for (int i = 1; i <= n; i++) {
        if (mx == res[i]) cout << i << ' ';
    }
    return 0;
}