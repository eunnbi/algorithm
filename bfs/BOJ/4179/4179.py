from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def main():
    n, m = map(int, input().split(' '))

    arr = [[''] * m for _ in range(n)]
    personQueue = deque()
    fireQueue = deque()
    personDist = [[-1] * m for _ in range(n)]
    fireDist = [[-1] * m for _ in range(n)]

    for i in range(n):
        str = input()
        for j in range(m):
            arr[i][j] = str[j]
            if (arr[i][j] == 'J'):
                personQueue.append([i, j])
                personDist[i][j] = 0
            elif (arr[i][j] == 'F'):
                fireQueue.append([i, j])
                fireDist[i][j] = 0
    
    while fireQueue:
        x, y = fireQueue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                continue
            if (fireDist[nx][ny] != -1 or arr[nx][ny] == '#'):
                continue
            fireQueue.append([nx, ny])
            fireDist[nx][ny] = fireDist[x][y] + 1
    
    while personQueue:
        x, y = personQueue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                print(personDist[x][y] + 1)
                return
            if (personDist[nx][ny] != -1 or arr[nx][ny] == '#'):
                continue
            if (fireDist[nx][ny] != -1 and fireDist[nx][ny] <= personDist[x][y] + 1):
                continue
            personQueue.append([nx, ny])
            personDist[nx][ny] = personDist[x][y] + 1

    print("IMPOSSIBLE")

if __name__ == "__main__":
    main()
