from collections import deque
import sys

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

NOT_VISITED = -1

def main():
    t = int(input())
    for _ in range(t):
        m, n = map(int, input().split(' '))

        arr = [[''] * m for _ in range(n)]
        fireQueue = deque()
        personQueue = deque()
        personDist = [[NOT_VISITED] * m for _ in range(n)]
        fireDist = [[NOT_VISITED] * m for _ in range(n)]

        for i in range(n):
            str = sys.stdin.readline().rstrip()
            for j in range(m):
                arr[i][j] = str[j]
                if (arr[i][j] == '@'):
                    personQueue.append([i, j])
                    personDist[i][j] = 0
                elif (arr[i][j] == '*'):
                    fireQueue.append([i, j])
                    fireDist[i][j] = 0
        
        while fireQueue:
            x, y = fireQueue.popleft()
            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                    continue
                if (fireDist[nx][ny] != NOT_VISITED or arr[nx][ny] == '#'):
                    continue
                fireQueue.append([nx, ny])
                fireDist[nx][ny] = fireDist[x][y] + 1
        
        isPossible = False
        while personQueue:
            x, y = personQueue.popleft()

            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                    print(personDist[x][y] + 1)
                    isPossible = True
                    break
                if (personDist[nx][ny] != NOT_VISITED or arr[nx][ny] == '#'):
                    continue
                if (fireDist[nx][ny] != NOT_VISITED and fireDist[nx][ny] <= personDist[x][y] + 1):
                    continue
                personQueue.append([nx, ny])
                personDist[nx][ny] = personDist[x][y] + 1
            
            if (isPossible):
                break
        
        if not isPossible:
            print('IMPOSSIBLE')

if __name__ == "__main__":
    main()