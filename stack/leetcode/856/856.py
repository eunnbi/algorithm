def scoreOfParentheses(s: str) -> int:
    stack = []
    for char in s:
        if (char == '('):
            stack.append(char)
        else:
            if (stack[-1] == '('):
                stack.pop()
                stack.append('1')
            else:
                sum = 0
                while (stack and stack[-1] != '('):
                    sum += int(stack.pop())
                stack.pop()
                stack.append(str(2 * sum))
    sum = 0
    while (stack):
        sum += int(stack.pop())
    return sum
