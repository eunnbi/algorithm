from collections import deque

dx1 = [-1, -1, 1, 1, -2, -2, 2, 2]
dy1 = [2, -2, 2, -2, 1, -1, 1, -1]

dx2 = [-1, 1, 0, 0]
dy2 = [0, 0, 1, -1]

def main():
    k = int(input())
    m, n = map(int, input().split(' '))

    arr = [[0] * m for _ in range(n)]

    for i in range(n):
        str = input().split(' ')
        for j in range(m):
            arr[i][j] = int(str[j])
               
    visited = [[[False] * (k + 1) for _ in range(m)] for _ in range(n)]
    queue = deque()
    queue.append([0, 0, 0, 0])
    
    while queue:
        curX, curY, curK, dist = queue.popleft()

        if (curX == n - 1 and curY == m - 1):
            print(dist)
            return

        if (curK < k):
            for i in range(8):
                nx, ny, nk = curX + dx1[i], curY + dy1[i], curK + 1
                if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                    continue
                if (visited[nx][ny][nk] or arr[nx][ny] == 1):
                    continue
                queue.append([nx, ny, nk, dist + 1])
                visited[nx][ny][nk] = True
        
        for i in range(4):
            nx, ny, nk = curX + dx2[i], curY + dy2[i], curK
            if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                continue
            if (visited[nx][ny][nk] or arr[nx][ny] == 1):
                continue
            queue.append([nx, ny, nk, dist + 1])
            visited[nx][ny][nk] = True
    
    print(-1)

        
if __name__ == "__main__":
    main()
