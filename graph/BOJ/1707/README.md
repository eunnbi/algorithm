# 이분 그래프 🥇

```cpp
#include <iostream>
#include <vector>
#include <queue>
#define NOT_VISITED -1
using namespace std;

vector<int> adj[20002];
int vis[20002];

bool bfs(int start) {
    queue<int> q;
    vis[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt: adj[cur]) {
            if (vis[nxt] == NOT_VISITED) {
                vis[nxt] = 1 - vis[cur];
                q.push(nxt);
            }
            else if (vis[nxt] != (1 - vis[cur])) {
                return false;
            }
        }
    }
    return true;
}

int main()  {
    int k, n, m, u, v;
    cin >> k;
    while (k--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        fill(vis + 1, vis + n + 1, NOT_VISITED);
        string res = "YES\n";
        for (int i = 1; i <= n; i++) {
            if (vis[i] != NOT_VISITED) continue;
            if (!bfs(i)) {
                res = "NO\n";
                break;
            }
        }
        cout << res;

        // ⚠️ 인접 리스트 초기화!!
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
    }
    return 0;
}
```

- 이분 그래프는 그래프의 모든 정점이 두 그룹으로 나뉘어지고 서로 다른 그룹의 정점만이 간선으로 연결된 그래프이다.
- 서로 다른 그룹인지 판단하기 위해 `vis` 배열 원소 값을 방문하지 않았다면 `-1`, 방문했다면 `0` 혹은 `1`로 한다.
- BFS를 수행할 때 만약 이미 방문했던 정점이라면 다른 그룹인지 판단하는 로직을 추가했다.
