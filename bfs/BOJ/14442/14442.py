from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def main():
    n, m, k = map(int, input().split())
    arr = [[0] * m for _ in range(n)]

    for i in range(n):
        str = input()
        for j in range(m):
            arr[i][j] = int(str[j])
    
    visited = [[[False] * (k + 1) for _ in range(m)] for _ in range(n)]
    queue = deque()
    queue.append([0, 0, 0, 0])
    visited[0][0][0] = True

    while queue:
        curX, curY, curK, dist = queue.popleft()

        if (curX == n - 1 and curY == m - 1):
            print(dist + 1)
            return
        
        for i in range(4):
            nx, ny = curX + dx[i], curY + dy[i]
            if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                continue
            if (arr[nx][ny] == 0 and visited[nx][ny][curK] == False):
                queue.append([nx, ny, curK, dist + 1])
                visited[nx][ny][curK] = True
            if (arr[nx][ny] == 1 and curK < k and visited[nx][ny][curK + 1] == False):
                queue.append([nx, ny, curK + 1, dist + 1])
                visited[nx][ny][curK + 1] = True

    print(-1)


if __name__ == "__main__":
    main()
