
#define max(a, b) (((a) > (b)) ? (a) : (b))

int dp[501][501]; // dp[i][j] : maximum # of coins we can get using nums[i:j]

int maxCoins(int* nums, int numsSize){
    // base case
    for (int i = 0; i < numsSize; i++){
        for (int j = 0; j < numsSize; j++){
            dp[i][j] = 0;
        }
    }
    
    for (int i = numsSize - 1; i >= 0; i--){
        for (int j = i; j < numsSize; j++){
            for (int k = i; k <= j; k++){
                int left = k == i ? 0 : dp[i][k - 1];
                int right = k == j ? 0 : dp[k + 1][j];
                int curr = (i == 0 ? 1 : nums[i - 1]) * nums[k] * (j == numsSize - 1 ? 1 : nums[j + 1]);
                dp[i][j] = max(dp[i][j], left + curr + right);
            }
        }
    }
    return dp[0][numsSize - 1]; // answer case
}

/*
🌻 Approach
- Suppose we burst nums[k] last.
- We need to burst nums[i] ~ nums[k - 1] first. Then, we need to burst nums[k + 1] ~ nums[j].
- After that, we finally burst nums[k], getting nums[i - 1] * nums[k] * nums[j + 1]
⇒ A[i][j] = max(A[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] + A[k + 1][j])

- Be careful about handling boundary conditions

*/
// https://leetcode.com/problems/burst-balloons/