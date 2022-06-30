#include <string.h>

int dp[2001][2001]; // dp[i][j]: s[0:i]를 p[0:j]로 표현 가능한지 여부
bool isMatch(char * s, char * p){
    int len1 = strlen(s);
    int len2 = strlen(p);
    
    // base case
    dp[0][0] = 1; // 1. 아무것도 없는 문자열끼리 매칭
    for (int i = 1; i <= len1; i++){
        dp[i][0] = 0; // 2.
    }
  
    // 3. '*' matches the empty sequence
    for (int i = 1; i <= len2; i++){
        if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
        else dp[0][i] = 0;
    }
    
    for (int i = 1; i <= len1; i++){
        for (int j = 1; j <= len2; j++){
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*'){
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return dp[len1][len2]; // answer case
}

// https://leetcode.com/problems/wildcard-matching/