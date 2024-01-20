import sys
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

# 시작점이 여러 개지만, 시작점을 미리 알 수 없어 시작점을 찾고 BFS를 수행하는 문제이다.

def main():
    t = int(input())
    for _ in range(t):
        m, n, k = map(int, sys.stdin.readline().rstrip().split(' '))
        
        arr = [[0] * m for _ in range(n)]
        visited = [[False] * m for _ in range(n)]

        for _ in range(k):
            x, y = map(int, sys.stdin.readline().rstrip().split(' '))
            arr[y][x] = 1
        
        queue = deque()
        answer = 0

        for i in range(n):
            for j in range(m):
                if (visited[i][j] or arr[i][j] == 0):
                    continue
                
                queue.append([i, j])
                visited[i][j] = True

                while queue:
                    x, y = queue.popleft()
                    for k in range(4):
                        nx, ny = x + dx[k], y + dy[k]
                        if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                            continue
                        if (visited[nx][ny] or arr[nx][ny] == 0):
                            continue
                        queue.append([nx, ny])
                        visited[nx][ny] = True
                answer += 1
        print(answer)


if __name__ == "__main__":
    main()
