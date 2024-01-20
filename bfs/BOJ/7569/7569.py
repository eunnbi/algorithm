from collections import deque

dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, 1, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]

def main():
    m, n, h = map(int, input().split(' '))

    arr = [[list(map(int, input().split())) for _ in range(n)] for _ in range(h)]
    queue = deque()
    visited = [[[False] * m for _ in range(n)] for _ in range(h)]
    answer = 0

    for i in range(h):
        for j in range(n):
            for k in range(m):
                if (arr[i][j][k] == 1):
                    queue.append([i, j, k, 0])
                    visited[i][j][k] = True
    
    while queue:
        x, y, z, day = queue.popleft()

        for i in range(6):
            nx, ny, nz = x + dx[i], y + dy[i], z + dz[i]
            if (nx < 0 or nx >= h or ny < 0 or ny >= n or nz < 0 or nz >= m):
                continue
            if (visited[nx][ny][nz] or arr[nx][ny][nz] != 0):
                continue
            arr[nx][ny][nz] = 1
            queue.append([nx, ny, nz, day + 1])
            visited[nx][ny][nz] = True
            answer = max(answer, day + 1)
    
    for i in range(h):
        for j in range(n):
            for k in range(m):
                if (arr[i][j][k] == 0):
                    print(-1)
                    return
    print(answer)


if __name__ == "__main__":
    main()
