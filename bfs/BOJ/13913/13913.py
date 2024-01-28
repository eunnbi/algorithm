from collections import deque

def main():
    n, k = map(int, input().split(' '))

    visited = [False] * 200002
    backtracking = [0] * 200002
    queue = deque()
    queue.append([n, 0])
    visited[n] = True

    while queue:
        cur, second = queue.popleft()
        
        if (cur == k):
            print(second)
            res = []
            while (cur != n):
                res.append(str(cur))
                cur = backtracking[cur]
            res.append(str(cur))
            print(" ".join(reversed(res)))
            break

        for next in [cur - 1, cur + 1, 2 * cur]:
            if (next < 0 or next >= 200002):
                continue
            if (visited[next]):
                continue
            queue.append([next, second + 1])
            backtracking[next] = cur
            visited[next] = True


if __name__ == "__main__":
    main()