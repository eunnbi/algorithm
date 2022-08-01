#include <bits/stdc++.h>
using namespace std;

int T, N;
int dp[41][2];

int main(void) {
    cin >> T;
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    while (T--) {
        cin >> N;
        for (int i = 2; i <= N; i++) {
            dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
            dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
        }
        printf("%d %d\n", dp[N][0], dp[N][1]);
    }
    return 0;
}