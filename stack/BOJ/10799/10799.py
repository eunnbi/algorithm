def main():
    string = input()
    stack = []
    res = 0
    for i in range(len(string)):
        if (string[i] == '('):
            stack.append(string[i])
        else:
            if (string[i-1] == '('):
                stack.pop()
                res += len(stack)
            else:
                stack.pop()
                res += 1
    print(res)

if __name__ == "__main__":
    main()
