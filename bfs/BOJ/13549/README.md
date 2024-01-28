# 숨바꼭질3

**🤯 오답 코드**

```python
from collections import deque

def main():
    n, k = map(int, input().split(' '))

    visited = [False] * 200002
    queue = deque()
    queue.append([n, 0])
    visited[n] = True
    
    while queue:
        cur, second = queue.popleft()

        if (cur == k):
            print(second)
            return

        for next in [cur - 1, cur + 1, 2 * cur]:
            if (next < 0 or next >= 200002):
                continue
            if (visited[next]):
                continue
            if (next == 2 * cur):
                queue.append([next, second])
            else:
                queue.append([next, second + 1])
            visited[next] = True

if __name__ == "__main__":
    main()
```

**반례**

- 입력: `2 7`
- 출력: `2`
- 정답: `1`

**✏️ 풀이**

- 순간이동은 걷는 이동보다 더 빠르기 때문에, 이동할 때 우선순위가 더 높다.
- 순간 이동을 할 경우 해당 좌표를 덱의 앞에 넣는다.
- 걷는 이동을 할 경우 해당 좌표를 덱의 뒤에 넣는다.

   → 덱의 가장 앞쪽에 있는 좌표를 꺼내므로 순간이동의 우선순위를 높게 처리할 수 있다.

> **0-1 BFS**
> 가중치가 0과 1만 있는 그래프에서 최단 경로를 구하는 방법, ‘deque’를 이용하여 가중치가 0인 간선에 연결된 정점은 큐의 맨 앞에 넣는다.


> **BFS**
> “*모든 간선의 가중치가 동일*”하다는 전체 하의 최단 경로를 구한다.