from collections import deque
import sys

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def main():
    n, m, k = map(int, sys.stdin.readline().rstrip().split(' '))
    arr = [[0] * m for _ in range(n)]

    for i in range(n):
        str = sys.stdin.readline().rstrip()
        for j in range(m):
            arr[i][j] = int(str[j])

    visited = [[[False] * (k + 1) for _ in range(m)] for _ in range(n)]
    queue = deque()
    queue.append([0, 0, 0, True, 0])
    visited[0][0][0] = True

    while queue:
        curX, curY, curK, isDay, dist = queue.popleft()
        
        if (curX == n - 1 and curY == m - 1):
            print(dist + 1)
            return

        for i in range(4):
            nx, ny = curX + dx[i], curY + dy[i]
            if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                continue
            if (arr[nx][ny] == 0 and not visited[nx][ny][curK]):
                queue.append([nx, ny, curK, not isDay, dist + 1])
                visited[nx][ny][curK] = True
            if (arr[nx][ny] == 1 and curK < k and not visited[nx][ny][curK + 1]):
                if isDay:
                    queue.append([nx, ny, curK + 1, not isDay, dist + 1])
                    visited[nx][ny][curK + 1] = True
                else:
                    queue.append([curX, curY, curK, not isDay, dist + 1])
    print(-1)

if __name__ == "__main__":
    main()
