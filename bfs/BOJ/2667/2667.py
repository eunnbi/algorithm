from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def main():
    n = int(input())
    arr = [[0] * n for _ in range(n)]

    for i in range(n):
        str = input()
        for j in range(n):
            arr[i][j] = int(str[j])
    
    answer = 0
    nums = []
    
    visited = [[False] * n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if (visited[i][j] or arr[i][j] == 0):
                continue
            
            queue = deque()
            queue.append([i , j])
            visited[i][j] = True
            cnt = 1

            while queue:
                x, y = queue.popleft()
                for k in range(4):
                    nx, ny = x + dx[k], y + dy[k]
                    if (nx < 0 or nx >= n or ny < 0 or ny >= n):
                        continue
                    if (visited[nx][ny] or arr[nx][ny] == 0):
                        continue
                    queue.append([nx, ny])
                    visited[nx][ny] = True
                    cnt += 1
            
            answer += 1
            nums.append(cnt)
    
    nums.sort()
    print(answer)
    for num in nums:
        print(num)
    


if __name__ == "__main__":
    main()