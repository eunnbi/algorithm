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

        for next in [2 * cur, cur - 1, cur + 1]:
            if (next < 0 or next >= 200002):
                continue
            if (visited[next]):
                continue
            if (next == 2 * cur):
                queue.appendleft([next, second])
            else:
                queue.append([next, second + 1])
            visited[next] = True


if __name__ == "__main__":
    main()
