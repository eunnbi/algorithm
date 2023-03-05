# 트리 순회 🥇

## 오답 코드 (재귀)

```cpp
#include <iostream>
using namespace std;

int n;
int lc[100002];
int rc[100002];
int lastNode, res, num;
bool finish;

void traversal(int cur) {
    res++;
    num++;
    if (cur == lastNode && n == num) finish = true;
    if (lc[cur]) {
        traversal(lc[cur]);
        if (!finish) res++;
    }
    if (rc[cur]) {
        traversal(rc[cur]);
        if (!finish) res++;
    }
}

int main() {
    int a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (b != -1) lc[a] = b;
        if (c != -1) rc[a] = c;
    }
    int cur = 1;
    while (rc[cur]) cur = rc[cur];
    lastNode = cur;
    traversal(1);
    cout << res - 1;
    return 0;
}
```

## 정답 코드 (반복문)

> 재귀 대신 반복문을 사용하여 문제를 해결했다.

```cpp
#include <iostream>
using namespace std;

int n;
int lc[100002];
int rc[100002];
int p[100002];
bool vis[100002];

int main() {
    int a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (b != -1) {
            lc[a] = b;
            p[b] = a;
        }
        if (c != -1) {
            rc[a] = c;
            p[c] = a;
        }
    }
    int lastNode = 1;
    while (rc[lastNode]) lastNode = rc[lastNode];
    int cur = 1;
    int res = 0;
    while (true) {
        if (lc[cur] && !vis[lc[cur]]) {
            cur = lc[cur];
            vis[cur] = true;
            res++;
        }
        else if (rc[cur] && !vis[rc[cur]]) {
            cur = rc[cur];
            vis[cur] = true;
            res++;
        }
        else if (lastNode == cur) break;
        else if (p[cur]) {
            cur = p[cur];
            res++;
        }
    }
    cout << res;
    return 0;
}
```

> [문제 보러가기](https://www.acmicpc.net/problem/22856)