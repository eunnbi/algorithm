#include <string.h>

// 1.  Bottom-up
int dp[20001]; // dp[i] = true if we can make 'i'
bool canPartition(int* nums, int numsSize){
    int total = 0;
    for (int i = 0; i < numsSize; i++) total += nums[i];
    if (total % 2) return 0; // 전체 합이 홀수이면 false
    
    for (int i = 0; i <= total / 2; i++){
        dp[i] = 0;  // false로 초기화
    }
    
    dp[0] = 1; // base case
    for (int i = 0; i < numsSize; i++){
        for (int j = total / 2; j >= nums[i]; j--){
            if (dp[j - nums[i]]) dp[j] = 1; // dp[j] is true if dp[j - nums[i]] is true
        }
    }
    
    return dp[total / 2]; // answer case
}


// 2. Top-down + Memoization
int memo[10001][1000]; // -1 or 0 or 1
bool sol(int* nums, int numsSize, int target, int i){
    if (target < 0) return false;
    if (i == numsSize){
        if (target == 0) return 1;
        else return 0;
    }
    if (memo[target][i] != -1) return memo[target][i];

    return memo[target][i] = sol(nums, numsSize, target, i + 1) || sol(nums, numsSize, target - nums[i], i + 1);
}

bool canPartition(int* nums, int numsSize){
    memset(memo, -1, sizeof(memo));
    int total = 0;
    for (int i = 0; i < numsSize; i++) total += nums[i];
    if (total % 2) return 0;
    
    return sol(nums, numsSize, total / 2, 0);
}

// https://leetcode.com/problems/partition-equal-subset-sum/