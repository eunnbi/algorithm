def main():   
    n = int(input())
    str = input()
    seq = [int(i) for i in str.split(' ')]
    res = []
    stack = []
    seq.reverse()
    for i in range(len(seq)):
        while (stack and stack[-1] <= seq[i]):
            stack.pop()
        if stack:
            res.append(stack[-1])
        else:
            res.append(-1)
        stack.append(seq[i])
    res.reverse()
    for i in res:
        print(i , end=' ')


if __name__ == "__main__":
    main()
