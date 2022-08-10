#include <bits/stdc++.h>
using namespace std;

int N, M;
string s1, s2;
int dp[1002][1002]; // dp[i][j] : s1[0:i]와 s2[0:j]의 LCS

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1;
    cin >> s2;
    int len1 = s1.length();
    int len2 = s2.length();

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1])});
        }
    }
    cout << dp[len1][len2];
    return 0;
}
// https://www.acmicpc.net/problem/9251