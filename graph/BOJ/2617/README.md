# 구슬 찾기 🥇

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> heavy[102]; // 간선 (u, v)가 u < v임을 나태나는 그래프
vector<int> light[102]; // 간선 (u, v)가 u > v임을 나태나는 그래프
bool vis[102];

int bfs(vector<int> adj[], int start) {
    queue<int> q;
    vis[start] = true;
    q.push(start);
    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt: adj[cur]) {
            if (vis[nxt]) continue;
            cnt++;
            vis[nxt] = true;
            q.push(nxt);
        }
    }
    return cnt;
}
int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        light[u].push_back(v);
        heavy[v].push_back(u);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        fill(vis + 1, vis + n + 1, false);
        int big = bfs(heavy, i);  // 자신보다 무거운 구슬의 개수
        int small = bfs(light, i); // 자신보다 가벼운 구슬의 개수
        if (big > ((n - 1) / 2) || small > ((n - 1) / 2)) res++;
    }
    cout << res;
    return 0;
}
```

- 무게가 중앙값인 구슬은 본인보다 가벼운 구슬과 무거운 구슬이 각각 `(n - 1) / 2`개 있어야 한다. 이 문제는 무게가 중앙값이 될 수 없는 구슬의 개수를 찾는 문제이기 때문에, 가벼운 구슬이 `(n - 1) / 2`개보다 많거나, 무거운 구슬이 `(n - 1) / 2`개보다 많은 구슬을 찾으면 된다.
- 무게의 대소 비교는 그래프로 표현할 수 있다. 간선이 (u, v)가 `u > v`임을 나타내는 그래프와 `u < v`임을 나타내는 그래프 2개에 대해 BFS를 수행하여 자신보다 가벼운 구슬의 개수와 무거운 구슬의 개수를 구할 수 있다.

> [문제 보러가기](https://www.acmicpc.net/problem/2617)
