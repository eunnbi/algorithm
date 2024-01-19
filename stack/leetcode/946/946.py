def validateStackSequences(pushed: list[int], popped: list[int]) -> bool:
    stack = []
    index = 0
    for num in pushed:
        stack.append(num)
        while (stack and stack[-1] == popped[index]):
            stack.pop()
            index += 1
    if (stack):
        return False
    else:
        return True