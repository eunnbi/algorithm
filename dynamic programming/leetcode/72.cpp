#include <string.h>
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define min3(a, b, c) (min(a, min(b, c)))

int dp[501][501]; // dp[i][j] : minimum # of operations needed to match word1[1:i] and word2[1:j]
int minDistance(char * word1, char * word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    
    // base case
    for (int i = 0; i < len1; i++) dp[i][0] = i;
    for (int j = 0; j < len2; j++) dp[0][j] = j;

    // convert word1 to word2
    for (int i = 1; i <= len1; i++){
        for (int j = 1; j <= len2; j++){
            if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            // insert : dp[i - 1][j] + 1
            // remove : dp[i][j - 1] + 1
            // replace : dp[i - 1][j - 1] + 1
        }
    }
    return dp[len1][len2]; // answer case
}

// https://leetcode.com/problems/edit-distance/