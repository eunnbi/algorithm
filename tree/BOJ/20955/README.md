# 민서의 응급 수술 🥇

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100002];
bool vis[100002];

void dfs(int cur) {
    vis[cur] = true;
    for (int nxt: adj[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int groupCnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i);
        groupCnt++;
    }
    cout << (groupCnt - 1) + (m + groupCnt - 1) - (n - 1);
    return 0;
}
```

👉 먼저, connected component의 개수(`=groupCnt`)를 구한다. `groupCnt - 1`개의 간선을 추가해 주어진 그래프를 연결 그래프로 만든다. 현재 그래프에는 `m + groupCnt - 1`개의 간선이 있고, 트리는 `n - 1`개의 간선이 있기 때문에, `(m + groupCnt - 1) - (n - 1)` 개의 간선을 제거해야 한다. 그래서 최종 답은 `(groupCnt - 1) + (m + groupCnt - 1) - (n - 1)` 이다.

> [문제 보러가기](https://www.acmicpc.net/problem/20955)
