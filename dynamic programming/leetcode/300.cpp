int dp[2501]; //  LIS 길이
int lengthOfLIS(int* nums, int numsSize){
    dp[0] = 1; // base case
    int max = 0;
    for (int i = 1; i < numsSize; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        if (max < dp[i]) max = dp[i];
    }
    return max;
}

/*
❣️ Approach
- very famous DP problem
- Choice at index 'i' affects the future choice
- But, never think about future. Only think about relating the "current" and the "past"!
- "dp[i]"
    - 'i' 번째 원소를 마지막으로 하는 LIS 길이
    - '1'~ 'i-1' 까지의 원소들 중에서 i번째 원소보다 작은 것들 중 가장 큰 dp 값 + 1
*/

// https://leetcode.com/problems/longest-increasing-subsequence/