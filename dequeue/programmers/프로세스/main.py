from collections import deque

def solution(priorities, location):
    answer = 0
    dq = deque([])
    for i in range(len(priorities)):
        dq.append(list([priorities[i], i]))
    while (dq):
        target = dq[0][0]
        index = dq[0][1]
        for i in range(len(dq)):
            if (target < dq[i][0]):
                target = dq[i][0]
                index = dq[i][1]
        if (index == location):
            answer += 1
            break
        while (dq[0][0] != target):
            dq.append(dq.popleft())
        dq.popleft()
        answer += 1
    return answer