from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def main():
    n, m, k = map(int, input().split(' '))
    arr = [[0] * m for _ in range(n)]

    for _ in range(k):
        y1, x1, y2, x2 = map(int, input().split(' '))
        for x in range(x1, x2):
            for y in range(y1, y2):
                arr[x][y] = 1

    answer = 0
    width = []
    queue = deque()
    visited = [[False] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if (visited[i][j] or arr[i][j] == 1):
                continue

            w = 1
            queue.append([i, j])
            visited[i][j] = True

            while queue:
                x, y = queue.popleft()
                for k in range(4):
                    nx, ny = x + dx[k], y + dy[k]
                    if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                        continue
                    if (visited[nx][ny] or arr[nx][ny] == 1):
                        continue
                    queue.append([nx, ny])
                    visited[nx][ny] = True
                    w += 1
            
            answer += 1
            width.append(w)

    print(answer)
    print(" ".join(list(map(str, sorted(width)))))
        
if __name__ == "__main__":
    main()
