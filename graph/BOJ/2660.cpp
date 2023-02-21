#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> adj[52];
int dist[52];
unordered_set<int> res[52];
int main() {
    int n, u, v;
    cin >> n;
    while (true) {
        cin >> u >> v;
        if (u == -1 && v == -1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        fill(dist + 1, dist + n + 1, -1);
        queue<int> q;
        q.push(i);
        dist[i] = 0;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt: adj[cur]) {
                if (dist[nxt] != -1) continue;
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            res[j].insert(dist[j]);
        }
    }
    int mn = 100;
    vector<int> candidate;
    for (int i = 1; i <= n; i++) {
        if (mn > res[i].size()) mn = res[i].size();
    }
    for (int i = 1; i <= n; i++) {
        if (mn == res[i].size()) candidate.push_back(i);
    }
    cout << mn << ' ' << candidate.size() << '\n';
    for (int val: candidate) cout << val << ' ';
    return 0;
}