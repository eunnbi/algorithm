def main():   
    n = int(input())
    stack = []
    res = 0
    for _ in range(n):
        height = int(input())
        while (stack and stack[-1] <= height):
            stack.pop()
        res += len(stack)
        stack.append(height)
    print(res)

if __name__ == "__main__":
    main()

