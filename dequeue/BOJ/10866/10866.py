from collections import deque
import sys

def main():
    n = int(input())
    dq = deque([])
    for _ in range(n):
        cmd = sys.stdin.readline().rstrip().split(' ')
        if (cmd[0] == "push_front"):
            dq.appendleft(cmd[1])
        elif (cmd[0] == "push_back"):
            dq.append(cmd[1])
        elif (cmd[0] == "pop_front"):
            print(dq.popleft() if dq else -1)
        elif (cmd[0] == "pop_back"):
            print(dq.pop() if dq else -1)
        elif (cmd[0] == "size"):
            print(len(dq))
        elif (cmd[0] == "empty"):
            print(0 if dq else 1)
        elif (cmd[0] == "front"):
            print(dq[0] if dq else -1)
        elif (cmd[0] == "back"):
            print(dq[len(dq) - 1] if dq else -1)


if __name__ == "__main__":
    main()
