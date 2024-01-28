# 확장 게임

**🤯 오답 코드**: 시간 초과 발생

```python
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def main():
    n, m, p = map(int, input().split(' '))
    move = list(map(int, input().split(' ')))
    arr = [[''] * m for _ in range(n)]
    visited = [[False] * m for _ in range(n)]
    queueArr = [deque() for _ in range(p)]
    res = [0 for _ in range(p)]

    for i in range(n):
        str = input()
        for j in range(m):
            arr[i][j] = str[j]
            if (arr[i][j] != '.' and arr[i][j] != '#'):
                queueArr[int(arr[i][j]) - 1].append([i, j])
                visited[i][j] = True
                res[int(arr[i][j]) - 1] += 1
    
    while True:
        isExpand = False
        for player in range(len(queueArr)):

            if not queueArr[player]:
                continue

            nextQueue = deque()
            isExpand = True

            for _ in range(move[player]): # 이 반복문을 없애 시간초과를 해결해야 함.
                while queueArr[player]:
                    x, y = queueArr[player].popleft()

                    for i in range(4):
                        nx, ny = x + dx[i], y + dy[i]
                        if (nx < 0 or nx >= n or ny < 0 or ny >= m):
                            continue
                        if (visited[nx][ny] or arr[nx][ny] == '#'):
                            continue
                        nextQueue.append([nx, ny])
                        visited[nx][ny] = True
                        res[player] += 1
                
                queueArr[player] = nextQueue
                nextQueue = deque()
        
        if not isExpand:
            break
    
    for num in res:
        print(num, end=' ')
    print('')

if __name__ == "__main__":
    main()
```

> **개선 방안**<br/>
> 플레이어가 이동할 수 있는 횟수 만큼 for문을 도는 대신 queue에 몇번째 이동하고 있는지 정보를 넣는다. 만약 현재 이동 횟수가 플레이어가 이동할 수 있는 횟수보다 같거나 크다면 현재 위치와 이동횟수를 리셋하여 다음 차례에 쓰일 큐에 넣는다.