def main():   
    n = int(input())
    seq = []
    stack = []
    res = ''
    count = 1
    
    for i in range(n):
        seq.append(int(input()))
    
    for num in seq:
        if (stack):
            top = stack[len(stack) - 1]
            if (top == num):
                stack.pop()
                res += '-\n'
            elif (top < num):
                while (count <= num):
                    stack.append(count)
                    count += 1
                    res += '+\n'
                stack.pop()
                res += '-\n'
            else:
                res = 'NO\n'
                break
        else:
            while (count <= num):
                stack.append(count)
                count += 1
                res += '+\n'
            stack.pop()
            res += '-\n'
    print(res, end='')


if __name__ == "__main__":
    main()
