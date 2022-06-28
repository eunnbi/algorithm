
#define max(a, b) (((a) > (b)) ? (a) : (b))

int predict(int* nums, int s, int e, int turn){
    if (s == e) return turn * nums[s];
    int a = turn * nums[s] + predict(nums, s + 1, e, -turn); // s 선택
    int b = turn * nums[e] + predict(nums, s, e - 1, -turn); // e 선택
    return turn * (max(turn * a, turn * b));
}

bool PredictTheWinner(int* nums, int numsSize){
    return predict(nums, 0, numsSize - 1, 1) >= 0;
}


/*
💡 Approach
- "optimal play" : The player considers all possibilities and makes a choice that results in the biggest score difference.
    ⇒ "consider all possibilities" : a hint for recursion

- This kind of problems, i.e., two players + optimal play + winner prediction, are usually recursion or dynamic programming problems.
- "predict(nums, s, e, turn)" : the maxinum score difference that P1 can make using the array nums[s:e]
    - answer: "predict(nums, s, e, turn)" ≥ 0
    - turn: 1 (p1) or -1 (p2)
        - if (turn == 1): add scores to the result
        - if (turn == -1): subtract scores to the result
        - res += turn * score
    - if the player takes the first number, "turns * nums[s] + predict(nums, s + 1, e, -turn)"
    - if the player takes the last number, "turns * nums[e] + predict(nums, s, e - 1, -turn)"
    - the condition of termination: "s == e"
*/

// https://leetcode.com/problems/predict-the-winner/