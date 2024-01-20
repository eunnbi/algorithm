# Breadth First Search

## BFS 정의

다차원 배열에서 각 칸을 방문할 때 너비를 우선으로 방문하는 알고리즘

## 구현 방법

1. 시작하는 칸을 **큐**에 넣고 방문했다는 표시를 남김
2. 큐에서 원소를 꺼내어 그 칸에 상하좌우로 인접한 칸에 대해 3번을 진행
3. 해당 칸을 이전에 방문했다면 pass, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 큐에 삽입
4. 큐가 빌 때까지 2번 반복

### 파이썬 코드

```python
from collections import deque

n, m = map(int, input.split())

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

visited = [[-1] * m for _ in range(n)]

def bfs(matrix):
	queue = deque([0, 0])
	visited[0][0] = 1
	
	while queue:
		x, y = queue.popleft()
		for i in range(4):
			nx, ny = x + dx[i], y + dy[i]
			if (nx < 0 or nx >= n or ny < 0 or ny >= m):
				continue
			if (visited[nx][ny] != -1 or matrix[nx][ny] != 1):
				continue
			queue.append([nx, ny])
			visited[nx][ny] = visited[x][y] + 1
```

### BFS를 구현할 때 주의해야 할 점

- 시작점에 방문했다는 표시를 남기지 않는다.
- 큐에 넣을 때 방문했다는 표시를 하는 대신 큐에서 빼낼 때 방문했다는 표시를 남긴다.
    
    ⇒ 같은 큐에 여러 번 들어가게 되면서 시간 초과나 메모리 초과가 발생
    
- 이웃한 원소가 배열의 범위를 벗어 났는지에 대한 체크 잘하기 (Out of bounds 에러 방지

## 시간복잡도

모든 칸이 큐에 1번씩 들어가므로 시간 복잡도는 칸이 N개일 때 O(N)