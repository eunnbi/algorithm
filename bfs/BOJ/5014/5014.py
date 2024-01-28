from collections import deque

def main():
    f, s, g, u, d = map(int, input().split(' '))

    d = [u, -d]
    arr = [-1] * (f + 1)
    queue = deque()
    queue.append(s)
    arr[s] = 0

    while queue:
        cur = queue.popleft()
        if (cur == g):
            print(arr[cur])
            return
        for i in range(2):
            next = cur + d[i]
            if (next <= 0 or next > f):
                continue
            if (arr[next] != -1):
                continue
            queue.append(next)
            arr[next] = arr[cur] + 1
    
    print('use the stairs')

if __name__ == "__main__":
    main()