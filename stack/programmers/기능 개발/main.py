import math

def solution(progresses, speeds):
    answer = []
    list = [math.ceil((100 - progresses[i]) / speeds[i]) for i in range(len(progresses))]
    stack = []
    for num in list:
        if (stack and stack[-1] >= num):
            stack.append(stack[-1])
            if (answer):
                answer[-1] += 1
            else:
                answer.append(1)
        else:
            stack.append(num)   
            answer.append(1)     
    return answer
