# Depth First Search

## DFS 정의

다차원 배열에서 각 칸을 방문할 때 깊이를 우선으로 방문하는 알고리즘

## 구현 방법

1. 시작하는 칸을 스택에 넣고 방문했다는 표시를 남김
2. 스택에서 원소를 꺼내어 그 칸과 상하좌우 인접한 칸에 대해 3번을 진행
3. 해당 칸을 이전에 방문했다면 pass, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 스택에 삽입
4. 스택이 빌 때까지 2번 반복

```python
from collections import deque

n, m = map(int, input.split())

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

visited = [[-1] * m for _ in range(n)]

def dfs(matrix):
	stack = [[0, 0]]
	visited[0][0] = 1
	
	while queue:
		x, y = stack.pop()
		for i in range(4):
			nx, ny = x + dx[i], y + dy[i]
			if (nx < 0 or nx >= n or ny < 0 or ny >= m):
				continue
			if (visited[nx][ny] != -1 or matrix[nx][ny] != 1):
				continue
			stack.append([nx, ny])
			visited[nx][ny] = visited[x][y] + 1
```

## 시간복잡도

모든 칸이 스택에 1번씩 들어가므로 시간 복잡도는 칸이 N일 때 O(N)

## BFS vs DFS

💡 방문 순서에 있어서 큰 차이가 있음.

- BFS: **자신과 거리가 가까운 칸부터** 순서대로 방문한다.
- DFS: 한 방향으로 막힐 때까지 쭉 방문한다. 그래서 각 칸마다 시작점으로부터 거리를 구할 수 없다.