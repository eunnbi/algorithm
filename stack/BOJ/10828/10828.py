import sys

def main():
    n = int(input())
    list = []
    for _ in range(n):
        str = sys.stdin.readline().rstrip()
        command = str.split(' ')
        if (command[0] == 'push'):
            list.append(command[1])
        elif (command[0] == 'pop'):
            print(list.pop() if list else -1)
        elif (command[0] == 'size'):
            print(len(list))
        elif (command[0] == 'empty'):
            print(0 if list else 1)
        else:
            print(list[len(list) - 1] if list else -1)

if __name__ == "__main__":
    main()