#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[102];
int dist[102];
int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int res;
    long long num = 0;
    long long mn = -1;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        fill(dist + 1, dist + n + 1, -1);
        q.push(i);
        dist[i] = 0;
        num = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nxt: adj[cur]) {
                if (dist[nxt] != -1) continue;
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
                num += dist[nxt];
            }
        }
        if (mn == -1 || mn > num) {
            mn = num;
            res = i;
        }
    }
    cout << res;
    return 0;
}