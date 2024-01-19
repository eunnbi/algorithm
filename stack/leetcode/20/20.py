def isValid( s: str) -> bool:
    stack = []
    for char in s:
        if (char == '(' or char == '{' or char == '['):
            stack.append(char)
        elif (char == ')'):
            if (stack and stack[-1] == '('):
                stack.pop()
            else:
                return False
        elif (char == '}'):
            if (stack and stack[-1] == '{'):
                stack.pop()
            else:
                return False
        else:
            if (stack and stack[-1] == '['):
                stack.pop()
            else:
                return False
    if (stack):
        return False
    else:
        return True
    