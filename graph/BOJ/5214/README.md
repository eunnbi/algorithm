# 환승 🥇

## 메모리 초과나는 코드

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100002]; // ⚠️ 메모리 초과 발생
int dist[100002];
int temp[1002];
int main() {
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> temp[j];
        }
        for (int u = 0; u < k; u++) {
            for (int v = u + 1; v < k; v++) {
                adj[temp[u]].push_back(temp[v]);
                adj[temp[v]].push_back(temp[u]);
            }
        }
    }
    queue<int> q;
    q.push(1);
    dist[1] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == n) {
            cout << dist[n];
            return 0;
        }
        for (int nxt: adj[cur]) {
            if (dist[nxt] != 0) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    cout << -1;
    return 0;
}
```

- 같은 하이퍼튜브에 속한 역들을 모두 간선으로 이어 그래프를 만들려 하면 메모리 초과가 발생한다.
- 각각의 모든 하이터튜브가 모든 역을 연결한다고 가정하면 최악의 상황에서 `100억 * 4byte` 메모리가 사용되고 256MB 메모리 제한을 초과한다.

<br/>

## 최종 제출 코드

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> hypertube[1002]; // 하이퍼튜브가 연결하는 역들을 저장한다.
vector<int> station[100002]; // 역들이 속한 하이퍼튜브를 저장한다.
int dist[100002];
int main() {
    int n, k, m, num;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> num;
            station[num].push_back(i);
            hypertube[i].push_back(num);
        }
    }
    queue<int> q;
    q.push(1);
    dist[1] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == n) {
            cout << dist[n];
            return 0;
        }
        // 같은 하이퍼튜브에 속한 역들을 탐색한다.
        for (int tube: station[cur]) {
            for (int nxt: hypertube[tube]) {
               if (dist[nxt] != 0) continue;
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
    cout << -1;
    return 0;
}
```
