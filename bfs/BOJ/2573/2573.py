from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def getNum(n, m, arr):
    num = 0
    queue = deque()
    visited = [[False] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if (visited[i][j] or arr[i][j] == 0):
                continue

            queue.append([i, j])
            visited[i][j] = True

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
            num += 1

    return num


def main():
    n, m = map(int, input().split(' '))
    arr = [list(map(int, input().split(' '))) for _ in range(n)]

    num = getNum(n, m, arr)
    answer = 0

    while (num < 2):
        tmp = [[0] * m for _ in range(n)]
        
        for i in range(n):
            for j in range(m):
                if (arr[i][j] == 0):
                    continue
                adjacent = 0
                for k in range(4):
                    if (arr[i + dx[k]][j + dy[k]] == 0):
                        adjacent += 1
                tmp[i][j] = max(arr[i][j] - adjacent, 0)
        
        for i in range(n):
            for j in range(m):
                arr[i][j] = tmp[i][j]

        num = getNum(n, m, arr)

        if (num == 0):
            answer = 0
            break
        else:
            answer += 1
    
    print(answer)
    
        
if __name__ == "__main__":
    main()
