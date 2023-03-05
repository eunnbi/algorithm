# 트리 🥇

## 오답 코드

```cpp
#include <iostream>
using namespace std;

int delNode;
int lc[51];
int rc[51];
int res;

void traversal(int cur) {
    if (cur == delNode) return;
    if (lc[cur]) traversal(lc[cur]);
    if (rc[cur]) traversal(rc[cur]);
    if (!lc[cur] && !rc[cur]) res++;
}

int main() {
    int n, num, root;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num == -1) root = i;
        else {
            if (lc[num]) rc[num] = i;
            else lc[num] = i;
        }
    }
    cin >> delNode;
    traversal(root);
    cout << res;
    return 0;
}
```

틀린 이유
1. 삭제한 노드의 부모 노드가 리프 노드가 될 가능성을 고려하지 않음.
2. 이진 트리가 아닐 경우를 고려하지 않음.

<br/>

## 최종 제출 코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int delNode;
int p[51];
vector<int> child[51]; // 자식 노드 저장
int res;

void traversal(int cur) {
    if (child[cur].size() == 0) res++;
    for (int nxt: child[cur]) {
        traversal(nxt);
    }
}

int main() {
    int n, num, root;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num == -1) root = i;
        else {
            p[i] = num;
            child[num].push_back(i);
        }
    }
    cin >> delNode;
    if (delNode == root) {
        cout << 0;
        return 0;
    }
    int parent = p[delNode];
    child[parent].erase(find(child[parent].begin(), child[parent].end(), delNode)); // 자식 노드들 중 삭제할 노드 삭제
    traversal(root); // 순회하며 리프 노드 개수 구하기
    cout << res;
    return 0;
}
```

> [문제 보러가기](https://www.acmicpc.net/problem/1068)