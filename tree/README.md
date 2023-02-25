# Tree

## 정의와 성질

- 무방향이면서 사이클이 없는 연결 그래프 (Undirected Acyclic Connected Graph)
- 연결 그래프이면서 임의의 간선을 제거하면 연결 그래프가 아니게 되는 그래프
- 임의의 두 점을 연결하는 simple path (정점이 중복해서 나오지 않는 경로) 가 유일하다.
- V개의 정점을 가지고 V-1개의 간선을 가진다.
- 사이클이 없는 연결 그래프이지만 임의의 간선을 추가하면 사이클이 생긴다.

<br/>

## 용어 정리

- parent: 1개 이상의 서브 트리를 갖는 정점을 말한다.
- child: 부모 정점과 간선으로 연결된 정점을 말한다.
- sibling: 부모가 같은 정점들을 말한다.
- ancestor: 루트까지의 경로에 존재하는 모든 정점들을 말한다.
- descendant: 서브트리에 있는 모든 정점들을 말한다.
- root: 트리에서 제일 꼭대기에 있는 정점을 말한다.
- leaf node (terminal node): 자식이 없는 정점을 말한다.
- internal node (non-terminal node) : 자식이 있는 정점을 말한다.
- level: 루트까지의 거리를 말한다. 루트의 레벨은 0이다.
- height: root와 leaf 사이의 가징 긴 경로 길이를 말한다. 트리의 높이는 정점들의 레벨 중 최댓값에서 1를 더한 값이다.
- degree: 정점의 서브트리 개수를 말한다. 트리의 차수는 정점들의 차수 중 최댓값이다.

<br/>

## BFS & DFS

```cpp
// BFS
vector<int> adj[10];
int p[10]; // 부모 배열
int depth[10]; // depth 배열

void bfs(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]) {
            if (p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur; // 부모 배열 채우기
            depth[nxt] = depth[cur] + 1; // depth 배열 채우기
        }
    }
}
```

```cpp
// DFS + 비재귀
vector<int> adj[10];
int p[10];
int depth[10];

void dfs(int root) {
    stack<int> s;
    s.push(root);
    while (!s.empty()) {
        int cur = s.front();
        s.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]) {
            if (p[cur] == nxt) continue;
            s.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
        }
    }
}
```

```cpp
// DFS + 재귀
vector<int> adj[10];
int p[10];
int depth[10];

void dfs(int cur) {
    cout << cur << ' ';
    for (int nxt : adj[cur]) {
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        depth[nxt] = depth[cur] + 1;
        dfs(nxt);
    }
}
```

<br/>

## 정점 개수 및 높이 구하기

```cpp
// 정점 개수 구하기
int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};
int countNodes(int cur) {
    int r = 0, l = 0;
    if (lc[cur]) r = countNodes(lc[cur]);
    if (rc[cur]) l = countNodes(rc[cur]);
    return 1 + r + l;
}
countNodes(1);
```

```cpp
// 높이 구하기
int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};
int countHeight(int cur) {
    int r = 0, l = 0;
    if (lc[cur]) r = countHeight(lc[cur]);
    if (rc[cur]) l = countHeight(rc[cur]);
    return 1 + max(r, l);
}
countHeight(1);
```

<br/>

## 이진 트리의 순회

- 이진트리는 각 노드의 자식이 2개 이하인 트리를 말한다.
- 이진 트리의 높이가 `k`라 했을 때, 정점 개수의 최솟값은 `k`, 최댓값은 `2^k - 1`이다.
- 정점 개수가 `n`이라 했을 때, 트리 높이의 최솟값은 `log2(n+1)`, 최댓값은 `n`이다.

<br/>

### 레벨 순회 (Level-order traversal)

- 레벨 순으로 정점을 방문하는 순회이다.

```cpp
int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};
void levelorder() { // root = 1
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        if (lc[cur]) q.push(lc[cur]);
        if (rc[cur]) q.push(rc[cur]);
    }
}
```

<br/>

### 전위 순회 (Preorder traversal)

1. 현재 정점을 방문한다.
2. 왼쪽 서브 트리를 전위 순회한다.
3. 오른쪽 서브 트리를 전위 순회한다.

```cpp
int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};
void preorder(int cur) {
    cout << cur << ' ';
    if (lc[cur] != 0) preorder(lc[cur]);
    if (rc[cur] != 0) preorder(rc[cur]);
}
preorder(1);
```

<br/>

### 중위 순회 (Inorder traversal)

1. 왼쪽 서브 트리를 중위 순회한다.
2. 현재 정점을 방문한다.
3. 오른쪽 서브 트리를 중위 순회한다.

```cpp
int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};
void inorder(int cur) {
    if (lc[cur] != 0) inorder(lc[cur]);
    cout << cur << ' ';
    if (rc[cur] != 0) inorder(rc[cur]);
}
inorder(1);
```

<br/>

### 후위 순회 (Postorder traversal)

1. 왼쪽 서브 트리를 후위 순회한다.
2. 오른쪽 서브 트리를 후위 순회한다.
3. 현재 정점을 방문한다.

```cpp
int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};
void postorder(int cur) {
    if (lc[cur] != 0) postorder(lc[cur]);
    if (rc[cur] != 0) postorder(rc[cur]);
    cout << cur << ' ';
}
postorder(1);
```
