# Breadth First Search

> 다차원 배열에서 각 원소에 접근할 때 **너비를 우선으로** 접근하는 알고리즘

<br/>

## Implementation

1. 시작하는 칸을 **큐**에 넣고 방문했다는 표시를 남김
2. 큐에서 원소를 꺼내어 그 칸에 상하좌우로 인접한 칸에 대해 `3`번을 진행
3. 해당 칸을 이전에 방문했다면 pass, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 큐에 삽입
4. 큐가 빌 때까지 `2`번 반복

💛 모든 칸이 큐에 1번씩 들어가므로 시간 복잡도는 O(N) (N : 배열의 크기)

```cpp
#include <bits/stdc++.h>
using namespace std;

// pair에서 first, second를 줄여서 쓰기 위해서 사용
#define X first
#define Y second

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0}, // 1이 파란 칸, 0이 빨간 칸에 대응
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} };

bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10; // n = 행의 수, m = 열의 수
int dx[4] = {1,0,-1,0}; // 상하좌우 네 방향을 의미
int dy[4] = {0,1,0,-1};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<pair<int,int> > Q;
  Q.push({0,0}); // 큐에 시작점인 (0, 0)을 삽입
  vis[0][0] = 1; // (0, 0)을 방문했다고 명시
  while(!Q.empty()){
    pair<int,int> cur = Q.front(); Q.pop();
    cout << '(' << cur.X << ", " << cur.Y << ") -> ";
    for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 배열의 범위 밖일 경우
      if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
      vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
      Q.push({nx,ny});
    }
  }
}
```

<br/>

## Common Mistakes

- 시작점에 방문했다는 표시를 남기지 않는다.
- 큐에 넣을 때 방문했다는 표시를 하는 대신 큐에서 빼낼 때 방문했다는 표시를 남긴다.
  ⇒ 같은 큐에 여러 번 들어가게 되면서 시간 초과나 메모리 초과가 발생
- 이웃한 원소가 배열의 범위를 벗어났는지에 대한 체크를 잘못했다.

<br/>

## ❓ Problems

| BOJ                                                                             |
| ------------------------------------------------------------------------------- |
| [그림](https://github.com/eunnbi/algorithm/blob/main/bfs/BOJ/1926.cpp)          |
| [미로찾기](https://github.com/eunnbi/algorithm/blob/main/bfs/BOJ/2178.cpp)      |
| [토마토](https://github.com/eunnbi/algorithm/blob/main/bfs/BOJ/7576.cpp)        |
| [불!](https://github.com/eunnbi/algorithm/blob/main/bfs/BOJ/4179.cpp)           |
| [숨바꼭질](https://github.com/eunnbi/algorithm/blob/main/bfs/BOJ/1697.cpps)     |
| [유기농 배추](https://github.com/eunnbi/algorithm/blob/main/bfs/BOJ/1012.cpp)   |
| [적록색약](https://github.com/eunnbi/algorithm/blob/main/bfs/BOJ/10026.cpp)     |
| [토마토](https://github.com/eunnbi/algorithm/blob/main/bfs/BOJ/7569.cpp)        |
| [나이트의 이동](https://github.com/eunnbi/algorithm/blob/main/bfs/BOJ/7562.cpp) |
| [불](https://github.com/eunnbi/algorithm/blob/main/bfs/BOJ/5427.cpp)            |
| [영역 구하기](https://github.com/eunnbi/algorithm/blob/main/bfs/BOJ/2583.cpp)   |
