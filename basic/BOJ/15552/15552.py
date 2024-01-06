import sys

def main():
    t = int(input())
    for _ in range(t):
        a, b = sys.stdin.readline().rstrip().split(' ')
        print(int(a) + int(b))


if __name__ == "__main__":
    main()