# 트리와 쿼리 🥇

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100002];
bool vis[100002];
int res[100002];

int dfs(int cur) {
    vis[cur] = true;
    if (res[cur] != 0) return res[cur]; // ⚠️ 메모이제이션하지 않으면 시간초과 발생
    res[cur] = 1;
    for (int nxt: adj[cur]) {
        if (vis[nxt]) continue;
        res[cur] += dfs(nxt);
    }
    return res[cur];
}
int main() {
    // ⚠️ 아래 두 줄 코드 없으면 시간초과 발생
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n, r, q, u, v;
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(r);
    while (q--) {
        cin >> u;
        cout << res[u] << '\n';
    }
    return 0;
}

```

👉 DFS를 수행하여 각 정점의 서브트리에 속한 정점의 개수를 구한다.

> [문제 보러가기](https://www.acmicpc.net/problem/15681)
