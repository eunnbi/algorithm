# 경로찾기 🥈

## 오답 코드

```cpp
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
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt = 0; nxt < n; nxt++) {
                if (vis[nxt] || adj[cur][nxt] == 0) continue;
                vis[nxt] = true;
                q.push(nxt);
            }
        }
        for (int j = 0; j < n; j++) {
            if (vis[j]) cout << "1 ";
            else cout << "0 ";
        }
        cout << '\n';
    }
    return 0;
}
```

BFS를 수행할 때 출발 정점은 방문 처리가 되어 `vis[i]` 값이 true이기 때문에 위 코드에서 i번재 i줄은 항상 1로 출력된다. **하지만, i번재 i줄은 사이클이 존재해야 1로 출력되어야 한다.**

<br/>

## 최종 제출 코드

```cpp
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
                if (i == nxt) isCycle = true; // 사이클 발견
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
```

👉 BFS 수행 결과, 방문 여부를 통해 경로 존재 여부를 판단한다. 하지만, 출발 정점로부터 출발 정점으로 오는 경로는 사이클이 존재해야 가능하기 때문에, BFS 도중 사이클 여부를 체크하여 BFS가 끝난 후 출발 정점의 방문 여부를 적절히 수정한다.

> [문제 보러가기](https://www.acmicpc.net/problem/11403)
