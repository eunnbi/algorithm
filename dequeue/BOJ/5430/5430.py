from collections import deque
import sys

def main():
    t = int(input())
    for _ in range(t):
        cmd = sys.stdin.readline().rstrip()
        n = int(sys.stdin.readline().rstrip())
        string = sys.stdin.readline().rstrip().replace('[', '').replace(']', '')
        queue = deque(string.split(',') if string else [])
        isReversed = False
        isError = False
        for i in cmd:
            if (i == 'R'):
                isReversed = False if isReversed else True
            elif (isReversed):
                if (len(queue) > 0):
                    queue.pop()
                else:
                    isError = True
                    break
            else:
                if (len(queue) > 0):
                    queue.popleft()
                else:
                    isError = True
                    break
        if (isError):
            print('error')
        elif (isReversed):
            print(f"[{','.join(reversed(queue))}]")
        else:
            print(f"[{','.join(queue)}]")


if __name__ == "__main__":
    main()
