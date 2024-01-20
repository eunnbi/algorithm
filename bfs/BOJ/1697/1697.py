from collections import deque

def main():
    n, m = map(int, input().split(' '))

    visited = [False] * 100002

    queue = deque()
    queue.append([n, 0])
    visited[n] = True

    while queue:
        cur, second = queue.popleft()
        print(cur, second)

        if (cur == m):
            print(second)
            break

        for nxt in [cur - 1, cur + 1, 2 * cur]:
            if (nxt < 0 or nxt > 100000):
                continue
            if (visited[nxt]):
                continue
            queue.append([nxt, second + 1])
            visited[nxt] = True


if __name__ == "__main__":
    main()
