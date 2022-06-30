int dp[10001];
int numSquares(int n){
    int min;
    dp[0] = 0; // base case
    for (int i = 1; i <= n; i++){
        min = i;
        for (int j = 1; j * j <= i; j++){
            if (min > dp[i - j * j]) min = dp[i - j * j]; 
        }
        dp[i] = min + 1;
    }
    return dp[n]; // answer case
}

/*
 dp[i]
= the least nubmer of perfect squares that sum to i
= min(dp[i - 1], dp[i - 4], dp[i - 9], …) + 1
= min(dp [i - j * j]) + 1 (i - j * j ≥ 0)
*/

// https://leetcode.com/problems/perfect-squares/