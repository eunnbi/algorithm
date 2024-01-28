from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def solution(maps):
    n = len(maps)
    m = len(maps[0])

    visited = [[False] * m for _ in range(n)]
    queue = deque()
    queue.append([0, 0, 0])
    visited[0][0] = True;

    while queue:
        x, y, dist = queue.popleft()
        
        if (x == n - 1 and y == m - 1):
            return dist + 1
        
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                continue
            if (visited[nx][ny] or maps[nx][ny] == 0):
                continue
            queue.append([nx, ny, dist + 1])
            visited[nx][ny] = True
    
    return -1
