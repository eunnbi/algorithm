#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))


// 1. Bottom-up
int dp[1000][1000]; 
// dp[i][j] : the length of the long palindromic subsequence we can get only using s[i:j]

int longestPalindromeSubseq(char * s){
    int len = strlen(s);

    // base case
    for (int i = 0; i < len; i++){
        dp[i][i] = 1;
    }
    
    for (int i = len - 1; i >= 0; i--){
        for (int j = i + 1; j < len; j++){
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][len - 1];  // answer case
}

// 2. Top-down + Memoization
int memo[1001][1001];

int sol(char* s, int left, int right){
    if (left == right) return 1;
    if (left > right) return 0;
    if (memo[left][right] != -1) return memo[left][right];
    if (s[left] == s[right]) return memo[left][right] = sol(s, left + 1, right - 1) + 2;
    return memo[left][right] = max(sol(s, left + 1, right), sol(s, left, right - 1));
}

int longestPalindromeSubseq(char * s){
    memset(memo, -1, sizeof(memo));
    return sol(s, 0, strlen(s) - 1);
}

// https://leetcode.com/problems/longest-palindromic-subsequence/