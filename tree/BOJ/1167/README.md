# 트리의 지름 🥇

## 시간초과 나는 코드

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> adj[100002];
int dist[100002];
int res;
void dfs(int cur) {
    for (auto nxt: adj[cur]) {
        if (dist[nxt.first] != -1) continue;
        dist[nxt.first] = dist[cur] + nxt.second;
        res = max(res, dist[nxt.first]);
        dfs(nxt.first);
    }
}
int main() {
    int n, u, v, w;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> u;
        while (true) {
            cin >> v;
            if (v == -1) break;
            cin >> w;
            adj[u].push_back({ v, w });
            adj[v].push_back({ u, w });
        }
    }
     for (int i = 1; i <= n; i++) {
        fill(dist + 1, dist + 1 + n, -1);
        dist[i] = 0;
        dfs(i);
    }
    cout << res;
    return 0;
}
```

- 모든 정점에 대해 DFS를 수행하면 시간초과가 발생한다.

<br/>

## 최종 제출 코드

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> adj[100002];
int dist[100002];
int maxNode, res;
void dfs(int cur) {
    for (auto nxt: adj[cur]) {
        if (dist[nxt.first] != -1) continue;
        dist[nxt.first] = dist[cur] + nxt.second;
        if (dist[nxt.first] > res) {
            res = dist[nxt.first];
            maxNode = nxt.first;
        }
        dfs(nxt.first);
    }
}
int main() {
    int n, u, v, w;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> u;
        while (true) {
            cin >> v;
            if (v == -1) break;
            cin >> w;
            adj[u].push_back({ v, w });
            adj[v].push_back({ u, w });
        }
    }
    fill(dist + 1, dist + 1 + n, -1);
    dist[1] = 0;
    dfs(1);
    fill(dist + 1, dist + 1 + n, -1);
    dist[maxNode] = 0;
    dfs(maxNode);
    cout << res;
    return 0;
}
```

- 임의의 정점에서 DFS를 수행하여 가장 거리가 먼 정점을 찾은 후, 해당 정점에서 DFS를 수행하여 찾은 가장 거리가 먼 정점이 정답이다.
- 총 2번의 DFS를 수행하면 된다.

> [문제 보러가기](https://www.acmicpc.net/problem/1167)
