from collections import deque

def main():
    n, k = input().split(' ')
    n = int(n)
    k = int(k)
    
    queue = deque([str(i + 1) for i in range(n)])
    res: list[str] = []

    while (queue):
        for _ in range(k):
            queue.append(queue.popleft())
        res.append(queue.pop())
    
    print(f'<{", ".join(res)}>')

if __name__ == "__main__":
    main()
