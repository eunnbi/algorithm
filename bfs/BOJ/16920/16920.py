from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def main():
    n, m, p = map(int, input().split(' '))
    step = list(map(int, input().split(' ')))
    arr = [[''] * m for _ in range(n)]
    visited = [[False] * m for _ in range(n)]
    queueArr = [deque() for _ in range(p)]
    res = [0 for _ in range(p)]

    for i in range(n):
        str = input()
        for j in range(m):
            arr[i][j] = str[j]
            if (arr[i][j] != '.' and arr[i][j] != '#'):
                queueArr[int(arr[i][j]) - 1].append([i, j, 0])
                visited[i][j] = True
                res[int(arr[i][j]) - 1] += 1
    
    while True:
        isExpand = False
        for player in range(len(queueArr)):

            if not queueArr[player]:
                continue

            nextQueue = deque()
            isExpand = True

            while queueArr[player]:
                x, y, s = queueArr[player].popleft()

                if (s >= step[player]):
                    nextQueue.append([x, y, 0])
                    continue

                for i in range(4):
                    nx, ny, ns = x + dx[i], y + dy[i], s + 1
                    if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                        continue
                    if (visited[nx][ny] or arr[nx][ny] == '#'):
                        continue
                    queueArr[player].append([nx, ny, ns])
                    visited[nx][ny] = True
                    res[player] += 1
            
            queueArr[player] = nextQueue
        
        if not isExpand:
            break
    
    for num in res:
        print(num, end=' ')
    print('')

if __name__ == "__main__":
    main()