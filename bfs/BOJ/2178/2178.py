import sys
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def main():
    n, m = map(int, input().split(' '))

    arr = [[0] * m for _ in range(n)]

    for i in range(n):
        str = sys.stdin.readline().rstrip()
        for j in range(m):
            arr[i][j] = int(str[j])
    
    dist = [[-1] * m for _ in range(n)]
    queue = deque()
    queue.append([0, 0])
    dist[0][0] = 0

    while queue:
        x, y = queue.popleft()    
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                continue
            if (dist[nx][ny] != -1 or arr[nx][ny] == 0):
                continue
            queue.append([nx, ny])
            dist[nx][ny] = dist[x][y] + 1

    print(dist[n - 1][m - 1] + 1)

if __name__ == "__main__":
    main()
