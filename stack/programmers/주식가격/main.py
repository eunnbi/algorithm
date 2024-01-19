def solution(prices):
    answer = []
    stack = []
    for i in range(len(prices) - 1, -1, -1):
        while (stack and stack[-1][0] >= prices[i]):
            stack.pop()
        end = stack[-1][1] if stack else len(prices) - 1
        answer.append(end - i)
        stack.append([prices[i], i])
    answer.reverse()
    return answer
