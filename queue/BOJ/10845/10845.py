from collections import deque
import sys

def main():
    n = int(input())
    queue = deque([])
    for _ in range(n):
        cmd = sys.stdin.readline().rstrip().split(' ')
        if (cmd[0] == "push"):
            queue.append(cmd[1])
        elif (cmd[0] == "pop"):
            print(queue.popleft() if (queue) else -1)
        elif (cmd[0] == "front"):
            print(queue[0] if (queue) else -1)
        elif (cmd[0] == "back"):
            print(queue[len(queue) - 1] if (queue) else -1)
        elif (cmd[0] == "empty"):
            print(0 if (queue) else 1)
        else:
            print(len(queue))

if __name__ == "__main__":
    main()
