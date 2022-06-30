#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int dp[1001][1001]; // dp[i][j] : the length of LCS of text1[0:i] and text[0:j] (0으로 초기화)
int longestCommonSubsequence(char * text1, char * text2){
    int len1 = strlen(text1);
    int len2 = strlen(text2);

    for (int i = 1; i <= len1; i++){ // 1-based indexing
        for (int j = 1; j <= len2; j++){
            if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
        }
    }
    return dp[len1][len2]; // answer case
}

// https://leetcode.com/problems/longest-common-subsequence/