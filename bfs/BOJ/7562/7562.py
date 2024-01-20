from collections import deque

dx = [-1, -1, 1, 1, -2, -2, 2, 2]
dy = [2, -2, 2, -2, 1, -1, 1, -1]

def main():
    t = int(input())

    for _ in range(t):
        l = int(input())
        x, y = map(int, input().split(' '))
        rx, ry = map(int, input().split(' '))
        visited = [[0] * l for _ in range(l)]

        queue = deque()
        queue.append([x, y, 0])
        visited[x][y] = True

        while queue:
            x, y, num = queue.popleft()
            
            if (x == rx and y == ry):
                print(num)
                break

            for i in range(8):
                nx, ny = x + dx[i], y + dy[i]
                if (nx < 0 or nx >= l or ny < 0 or ny >= l):
                    continue
                if (visited[nx][ny]):
                    continue
                queue.append([nx, ny, num + 1])
                visited[nx][ny] = True




if __name__ == "__main__":
    main()
