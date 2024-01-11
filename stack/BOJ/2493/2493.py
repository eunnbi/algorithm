def main():   
    n = int(input())
    str = input()
    towers = [int(i) for i in str.split(' ')]
    res = []
    stack = []
    for i in range(len(towers)):
        height = towers[i]
        while (stack and stack[-1][1] < height):
            stack.pop()
        if stack:
            res.append(stack[-1][0])
        else:
            res.append(0)
        stack.append([i + 1, height])
    
    for i in res:
        print(i , end=' ')


if __name__ == "__main__":
    main()