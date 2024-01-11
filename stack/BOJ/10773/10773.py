import sys

def main():
    k = int(input())
    list = []
    res = 0
    for _ in range(k):
        num = int(sys.stdin.readline().rstrip())
        if (num == 0):
            res -= list.pop()
        else:
            list.append(num)
            res += num
    print(res)


if __name__ == "__main__":
    main()