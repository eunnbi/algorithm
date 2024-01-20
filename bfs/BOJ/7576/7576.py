import sys
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

 # 시작점이 여러 개지만, 시작점을 미리 알 수 있어 BFS를 동시에 수행할 수 있는 문제이다.

def main():
    m, n = map(int, input().split(' '))

    arr = [[0] * m for _ in range(n)]
    queue = deque()
    visited = [[False] * m for _  in range(n)]
    answer = 0


    for i in range(n):
        str = sys.stdin.readline().rstrip().split(' ')
        for j in range(m):
            arr[i][j] = int(str[j])
            if (arr[i][j] == 1):
                queue.append([i, j, 0])
                visited[i][j] = True


    while queue:
        x, y, z = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                continue
            if (visited[nx][ny] or arr[nx][ny] != 0):
                continue
            arr[nx][ny] = 1
            queue.append([nx, ny, z + 1])
            visited[nx][ny] = True
            answer = max(answer, z + 1)
    
    for i in range(n):
        for j in range(m):
            if (arr[i][j] == 0):
                print(-1)
                return
    print(answer)
    


if __name__ == "__main__":
    main()
