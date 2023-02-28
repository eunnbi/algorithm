# 트리 🥇

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[502];
bool vis[502];
int p[502];
bool isTree; // flag

void dfs(int cur) {
    vis[cur] = true;
    for (int nxt: adj[cur]) {
        if (p[cur] == nxt) continue;
        if (vis[nxt]) { // 사이클 발견
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
            isTree = true; // flag 초기화!
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
```

👉 Connected Component 마다 DFS를 수행하고 사이클이 없다면 트리이고, 있다면 트리가 아니라고 판단하여 트리의 개수를 구하면 된다. DFS 수행에서 인접한 정점을 탐색할 때 자신의 부모 정점이 아니면서 이미 방문한 정점이 있다면 사이클이 존재한다는 것으로 판단한다.
