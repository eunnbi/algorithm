int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int sum = 0;
    for (int i = 0; i < gasSize; i++) sum += gas[i] - cost[i];
    if (sum < 0) return -1;
    int start;
    sum = -1;
    for (int i = 0; i < gasSize; i++){
        if (sum < 0) {
            sum = 0;
            start = i;
        }
        sum += gas[i] - cost[i];
    }
    return start;
}


/*
delta[i] = gas[i] - cost[i]

- If delta[i] ≥ 0, the remaining amount of gas increases after traveling to station i+1 ⇒ no problem
- If delta[i] < 0, the amount decreases. We must have enough amount of gas before traveling. => problem

💡  We can find out that the problem is somewhat related to the subrarray sum of delta
*/

// https://leetcode.com/problems/gas-station/