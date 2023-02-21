#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int adj[102][102];
bool vis[102];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        fill(vis, vis + n, false);
        queue<int> q;
        q.push(i);
        vis[i] = true;
        bool isCycle = false;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt = 0; nxt < n; nxt++) {
                if (adj[cur][nxt] == 0) continue;
                if (i == nxt) isCycle = true;
                if (vis[nxt]) continue;
                vis[nxt] = true;
                q.push(nxt);
            }
        }
        if (!isCycle) vis[i] = false;
        for (int j = 0; j < n; j++) {
            if (vis[j]) cout << "1 ";
            else cout << "0 ";
        }
        cout << '\n';
    }
    return 0;
}