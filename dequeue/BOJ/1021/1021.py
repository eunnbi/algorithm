from collections import deque
import math

def main():
    n, m = input().split(' ')
    n = int(n)
    m = int(m)
    list = input().split(' ')
    target = [int(i) for i in list]
    queue = deque([int(i + 1) for i in range(n)])
    res = 0
    for num in target:
        for index in range(len(queue)):
            if (queue[index] == num):
                break
        if (index < math.ceil(len(queue) / 2)):
            for _ in range(index):
                queue.append(queue.popleft())
                res += 1
            queue.popleft()
        else:
            for _ in range(len(queue) - index):
                queue.appendleft(queue.pop())
                res += 1
            queue.popleft()
    print(res)

if __name__ == "__main__":
    main()
