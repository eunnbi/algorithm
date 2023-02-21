# Graph

> 정점과 간선으로 이루어진 자료구조를 말한다. 무방향 그래프, 방향 그래프, 가중치 그래프 등 다양한 형태의 그래프가 존재한다.

<br/>

## Degree (차수)

- 차수는 정점과 인접한 간선의 개수를 말한다.
- 무방향 그래프에서의 간선의 개수는 모든 정점의 차수의 합의 절반과 같다.
- 방향 그래프에서는 `indegree`, `outdegree` 두 종류의 차수가 있다.
  - (e, b), (b, a), (b, d) => 정점의 b의 `indegree`: 1개, `outdegree`: 2개

<br/>

## Cycle

- 임의의 한 점에서 출발해 자기 자신으로 돌아올 수 있는 경로를 말한다.
- 그래프에 사이클이 있으면 순환 그래프 (cyclic graph), 없다면 비순환 그래프 (acyclic graph) 라고 한다.

<br/>

## 완전 그래프 vs 연결 그래프

- 모든 서로 다른 두 정점 쌍이 간선으로 연결된 그래프를 완전 그래프 (complete graph) 라고 한다.
  - 무방향 완전 그래프에는 `n(n - 1) / 2`개의 간선이 있고, 방향 완전 그래프에는 `n(n - 1)`개의 간선이 있다.
- 임의의 두 정점 사이에 경로가 항상 존재하는 그래프를 연결 그래프 (connected graph) 라고 한다.

<br/>

## 단순 그래프

- 두 정점 사이의 간선이 2개 이상 존재할 수 있고, 한 정점에서 시작해 같은 정점으로 들어오는 간선, 즉 루프(loop)가 있을 수 있다.
- 두 정점 사이의 간선이 1개 이하이고 루프가 존재하지 않는 그래프를 우리는 단순 그래프 (simple graph) 라고 한다.

<br/>

## 그래프 표현법

### 인접 행렬 (Adjacency Matrix)

- 가로와 세로 크기가 각각 `V` (정점의 개수)인 행렬을 이용하는 방식이다.
- 단순 그래프라고 가정할 때, 연결된 두 정점에는 1, 연결되지 않은 두 정점에는 0을 주어 그래프를 표현할 수 있다. 만약 단순 그래프가 아니라면 1 혹은 0이 아니라 간선의 개수로 변형할 수 있다.
- 어떤 두 정점이 연결되었는지 `O(1)`에 알 수 있다.
- 그래프의 간선 개수는 `O(|V|^2)`에 알 수 있다.
- 어떤 정점의 outdegree와 indegree는 각각 `O(|V|)`에 알 수 있다.
- 공간 복잡도는 `O(|V|^2)`이다. 만약 정점의 개수에 비해 간선의 개수가 적다면 많은 공간이 낭비될 수 있다.

#### 방향 단순 그래프

```cpp
int adj_matrix[10][10] = {};
int v, e;
cin >> v >> e;
for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    adj_matrix[u][v] = 1;
}
```

#### 무방향 단순 그래프

```cpp
int adj_matrix[10][10] = {};
int v, e;
cin >> v >> e;
for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}
```

<br/>

### 인접 리스트 (Adjacency List)

- 정점 개수 크기의 리스트를 만들어 각 리스트에 자신과 연결된 정점을 넣어 그래프를 표현하는 방식이다.
- 어떤 두 정점이 연결되었는지 `O(min(deg(u), deg(v)))`에 알 수 있다.
- 그래프의 간선 개수는 `O(|E|)`에 알 수 있다. (worst case)
- 어떤 정점의 outdegree는 `O(deg(v))`에 알 수 있다.
- 어떤 정점의 indegree는 `O(|E|)`에 알 수 있다. (worst case)
- 공간복잡도는 `O(|V|+|E|)`이다. 정점이 많고, 간선이 상대적으로 적은 상황에서 공간을 절약할 수 있다.

#### 방향 그래프

```cpp
vector<int> adj[10];
int v, e;
cin >> v >> e;
for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
}
```

#### 무방향 그래프

```cpp
vector<int> adj[10];
int v, e;
cin >> v >> e;
for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

> 두 정점의 연결 여부를 자주 확인하거나 간선의 개수가 정점의 개수의 제곱과 가까울 때 인접 행렬을 사용하는 것이 효율적이다. 특정 정점에 연결된 모든 정점을 자주 확인하거나 간선의 개수가 정점의 개수의 제곱보다 훨씬 작을 때는 인접 리스트를 사용하는 것이 효율적이다.

<br/>

## BFS

- 그래프에서 너비를 우선으로 방문하는 알고리즘을 말한다.
- 시작점에서 다른 모든 점으로의 최단 경로를 찾을 때 BFS를 이용할 수 있다.
- 시간복잡도: 인접행렬을 사용했을 때는 `O(V^2)`이고, 인접 리스트를 사용했을 때는 `O(|V|+|E|)` 이다.

### 연결 그래프에서의 BFS

```cpp
vector<int> adj[10];
bool vis[10];
void bfs() {
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (auto nxt: adj[cur]) {
            if (vis[nxt]) continue;
            vis[nxt] = true;
            q.push(nxt);
        }
    }
}
```

### 연결 그래프에서 1번 정점과의 거리 구하기

```cpp
// 거리 구하기
vector<int> adj[10];
int dist[10];
void bfs() {
    fill(dist, dist + 10, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (auto nxt: adj[cur]) {
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
}
```

### 연결 그래프가 아닐 때 BFS 수행

```cpp
vector<int> adj[10];
bool vis[10];
int v = 9; // 정점의 개수
void bfs() {
    queue<int> q;
    for (int i = 1; i <= v; i++) {
        if (vis[i]) continue;
        q.push(i);
        vis[i] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            cout << cur << ' ';
            for (auto nxt: adj[cur]) {
                if (vis[nxt]) continue;
                vis[nxt] = true;
                q.push(nxt);
            }
        }
    }
}
```

<br/>

## DFS

- 그래프에서 깊이를 우선으로 방문하는 알고리즘을 말한다.

### 연결 그래프에서의 DFS

```cpp
// 비재귀
vector<int> adj[10];
bool vis[10];
void dfs() {
    stack<int> s;
    s.push(1);
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        cout << cur << ' ';
        for (auto nxt: adj[cur]) {
            if (vis[nxt]) continue;
            s.push(nxt);
        }
    }
}
```

```cpp
// 재귀
vector<int> adj[10];
bool vis[10];
void dfs(int cur) {
    vis[cur] = true;
    cout << cur << ' ';
    for (auto nxt: adj[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}
```
