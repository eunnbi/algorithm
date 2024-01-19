from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer = 0
    dq = deque([])
    total_weight = 0
    truck_weights.reverse()

    while (truck_weights):
        if (dq and answer - dq[0][1] == bridge_length):
            total_weight -= dq.popleft()[0]
        num = truck_weights[-1]
        if (total_weight + num <= weight and len(dq) < bridge_length):
            dq.append([num, answer])
            total_weight += num
            truck_weights.pop()
        answer += 1

    while (dq):
        if (answer - dq[0][1] == bridge_length):
            dq.popleft()
        answer += 1
    
    return answer