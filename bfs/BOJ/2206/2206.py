from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def main():
    n, m = map(int, input().split(' '))
    arr = [[0] * m for _ in range(n)]

    for i in range(n):
        str = input()
        for j in range(m):
            arr[i][j] = int(str[j])

    visited = [[[False] * 2 for _ in range(m)] for _ in range(n)]
    queue = deque()
    queue.append([0, 0, 0, 0])

    while queue:
        x, y, k, dist = queue.popleft()

        if (x == n - 1 and y == m - 1):
            print(dist + 1)
            return

        if (k < 1):
            for i in range(4):
                nx, ny, nk = x + dx[i], y + dy[i], k + 1
                if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                    continue
                if (visited[nx][ny][nk]):
                    continue
                queue.append([nx, ny, nk, dist + 1])
                visited[nx][ny][nk] = True

        for i in range(4):
            nx, ny, nk = x + dx[i], y + dy[i], k
            if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                continue
            if (visited[nx][ny][nk] or arr[nx][ny] == 1):
                continue
            queue.append([nx, ny, nk, dist + 1])
            visited[nx][ny][nk] = True
    
    print(-1)


if __name__ == "__main__":
    main()