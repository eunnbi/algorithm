# 트리의 부모 찾기 🥈

## BFS

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100002];
int parent[100002];
int main() {
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt: adj[cur]) {
            if (parent[nxt] || parent[nxt] == cur) continue;
            parent[nxt] = cur;
            q.push(nxt);
        }
    }
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }
    return 0;
}
```

<br/>

## DFS + 재귀

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int p[100001];

void dfs(int cur) {
	for (int nxt : adj[cur]) {
		if (p[cur] == nxt) continue;
		p[nxt] = cur;
		dfs(nxt);
	}
}

int main(void) {
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);
	for (int i = 2; i <= n; i++) {
		cout << p[i] << '\n';
	}
	return 0;
}
```
