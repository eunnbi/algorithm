from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def main():
    n, m = map(int, input().split(' '))

    arr = [list(map(int, input().split(' '))) for _ in range(n)]
    
    visited = [[False] * m for _ in range(n)]
    queue = deque();
    answer = 0
    width = 0

    for i in range(n):
        for j in range(m):
            if (visited[i][j] or arr[i][j] == 0):
                continue
            
            queue.append([i, j])
            visited[i][j] = True
            w = 1

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
                    w += 1
            
            answer += 1
            width = max(width, w)
    
    print(answer)
    print(width)    


if __name__ == "__main__":
    main()
