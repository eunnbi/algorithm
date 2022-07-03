# Depth First Search

> 다차원 배열에서 각 원소에 접근할 때 **깊이를 우선으로** 접근하는 알고리즘

<br/>

## Implementation

1. 시작하는 칸을 **스택**에 넣고 방문했다는 표시를 남김
2. 스택에서 원소를 꺼내어 그 칸과 상하좌우 인접한 칸에 대해 `3`번을 진행
3. 해당 칸을 이전에 방문했다면 pass, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 스택에 삽입
4. 스택이 빌 때까지 `2`번 반복

💙 모든 칸이 스택에 1번씩 들어가므로 시간 복잡도는 O(N) (N : 배열의 크기)

```cpp
#include <bits/stdc++.h>
using namespace std;
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
  stack<pair<int,int> > S;
  S.push({0,0}); // 스택에 시작점인 (0, 0)을 삽입.
  vis[0][0] = 1; // (0, 0)을 방문했다고 명시
  while(!S.empty()){
    pair<int,int> cur = S.top(); S.pop();
    cout << '(' << cur.X << ", " << cur.Y << ") -> ";
    for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 배열의 범위 밖일 경우
      if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
      vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
      S.push({nx,ny});
    }
  }
}
```

<br/>

## BFS vs DFS

💡 방문 순서에 있어서 큰 차이가 있음.

- `BFS`: **자신과 거리가 가까운 칸부터** 순서대로 방문한다.
- `DFS`: 한 방향으로 막힐 때까지 쭉 방문한다.
