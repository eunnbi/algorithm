from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def main():
    n = int(input())
    arr = [[''] * n for _ in range(n)]

    for i in range(n):
        str = input()
        for j in range(n):
            arr[i][j] = str[j]

    answer = [0, 0]
    
    # 적록색약이 아닌 사람
    queue = deque()
    visited = [[False] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if (visited[i][j]):
                continue
            
            queue.append([i, j])
            visited[i][j] = True

            while queue:
                x, y = queue.popleft()

                for k in range(4):
                    nx, ny = x + dx[k], y + dy[k]
                    if (nx < 0 or nx >= n or ny < 0 or ny >= n):
                        continue
                    if (visited[nx][ny] or arr[nx][ny] != arr[i][j]):
                        continue
                    queue.append([nx, ny])
                    visited[nx][ny] = True
            
            answer[0] += 1
                


    # 적록색약인 사람
    queue = deque()
    visited = [[False] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if (visited[i][j]):
                continue
            
            queue.append([i, j])
            visited[i][j] = True

            while queue:
                x, y = queue.popleft()

                for k in range(4):
                    nx, ny = x + dx[k], y + dy[k]
                    if (nx < 0 or nx >= n or ny < 0 or ny >= n):
                        continue
                    if (visited[nx][ny]):
                        continue
                    if (arr[nx][ny] != arr[i][j]):
                        if (arr[nx][ny] == 'R' and arr[i][j] == 'G'):
                            pass
                        elif (arr[nx][ny] == 'G' and arr[i][j] == 'R'):
                            pass
                        else:
                            continue
                    
                    queue.append([nx, ny])
                    visited[nx][ny] = True
            
            answer[1] += 1
    print(f"{answer[0]} {answer[1]}")


if __name__ == "__main__":
    main()