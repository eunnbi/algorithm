from collections import deque
import sys

dx = [0, 0, 0, 0, -1, 1]
dy = [0, 0, -1, 1, 0, 0]
dz = [-1, 1, 0, 0, 0, 0]

def main():
    while True:
        l, r, c = map(int, input().split(' '))
        if (l == 0 and r == 0 and c == 0):
            break
        arr = [[[''] * c for _ in range(r)] for _ in range(l)]
        visited = [[[False] * c for _ in range(r)] for _ in range(l)]
        queue = deque()

        for i in range(l):
            for j in range(r):
                str = sys.stdin.readline().rstrip()
                for k in range(c):
                    arr[i][j][k] = str[k]
                    if (arr[i][j][k] == 'S'):
                        queue.append([i, j, k, 0])
                        visited[i][j][k] = True
            temp = input()

        isPossible = False
        while queue:
            x, y, z, dist = queue.popleft()
            if (arr[x][y][z] == 'E'):
                print(f"Escaped in {dist} minute(s).")
                isPossible = True
                break
            for i in range(6):
                nx, ny, nz = x + dx[i], y + dy[i], z + dz[i]
                if (nx < 0 or nx >= l or ny < 0 or ny >= r or nz < 0 or nz >= c):
                    continue
                if (visited[nx][ny][nz] or arr[nx][ny][nz] == '#'):
                    continue
                queue.append([nx, ny, nz, dist + 1])
                visited[nx][ny][nz] = True
        
        if not isPossible:
            print('Trapped!')

if __name__ == "__main__":
    main()
