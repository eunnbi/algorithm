def main():
    string = input()
    stack: list[str] = []
    for char in string:
        if (char == "(") or (char == '['):
            stack.append(char);
        else:
            partner = '(' if (char == ')') else '['
            weight = 2 if (char == ')') else 3
            if (stack):
                sum = 1 if (stack[-1] == partner) else 0
                while (stack and stack[-1] != partner):
                    if (stack[-1].isdecimal()):
                        sum += int(stack.pop())
                    else:
                        print(0)
                        return
                if (stack):
                    stack.pop()
                    stack.append(str(sum * weight))
                else:
                    print(0)
                    return    
            else:
                print(0)
                return
            
    sum = 0
    while (stack):
        if (stack[-1].isdecimal()):
            sum += int(stack.pop())
        else:
            print(0)
            return
    print(sum)


if __name__ == "__main__":
    main()
