from collections import deque
import sys

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def main():
    n = int(input())
    arr = [[0] * n for _ in range(n)]
    for i in range(n):
        str = sys.stdin.readline().rstrip().split(' ');
        for j in range(n):
            arr[i][j] = int(str[j])

    visited = [[False] * n for _ in range(n)]
    num = 1

    for i in range(n):
        for j in range(n):
            if (visited[i][j] or arr[i][j] == 0):
                continue

            queue = deque()
            queue.append([i, j])
            arr[i][j] = num;
            visited[i][j] = True

            while queue:
                x, y = queue.popleft()

                for k in range(4):
                    nx, ny = x + dx[k], y + dy[k]
                    if (nx < 0 or nx >= n or ny < 0 or ny >= n):
                        continue
                    if (visited[nx][ny] or arr[nx][ny] == 0):
                        continue
                    queue.append([nx, ny])
                    arr[nx][ny] = num;
                    visited[nx][ny] = True
            num += 1
    
    queue = deque()
    dist = [[-1] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if (arr[i][j] != 0):
                queue.append([i, j])
                dist[i][j] = 0
                    
    
    res = 1000000
    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if (nx < 0  or nx >= n or ny < 0 or ny >= n):
                continue
            if (arr[nx][ny] == arr[x][y]):
                continue
            if (arr[nx][ny] == 0):
                arr[nx][ny] = arr[x][y]
                queue.append([nx, ny])
                dist[nx][ny] = dist[x][y] + 1
            else:
                res = min(res, dist[nx][ny] + dist[x][y])

    print(res)

if __name__ == "__main__":
    main();
