import sys
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def main():
    n = int(input())

    arr = [[0] * n for _ in range(n)]
    end = 0
    answer = 0

    for i in range(n):
        str = sys.stdin.readline().rstrip().split(' ')
        for j in range(n):
            arr[i][j] = int(str[j])
            end = max(end, arr[i][j])

    for height in range(0, end):
        num = 0
        queue = deque()
        visited = [[False] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if (visited[i][j] or arr[i][j] <= height):
                    continue
                
                queue.append([i ,j])
                visited[i][j] = True
                
                while queue:
                    x, y = queue.popleft()

                    for k in range(4):
                        nx, ny = x + dx[k], y + dy[k]
                        if (nx < 0 or nx >= n or ny < 0 or ny >= n):
                            continue
                        if (visited[nx][ny] or arr[nx][ny] <= height):
                            continue
                        queue.append([nx, ny])
                        visited[nx][ny] = True
                num += 1
        answer = max(answer, num)
    print(answer)


if __name__ == "__main__":
    main()
