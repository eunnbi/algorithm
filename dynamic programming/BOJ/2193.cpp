#include <bits/stdc++.h>
using namespace std;

int N;
// dp[i][0] : 0으로 끝나는 i자리 이친수의 개수
// dp[i][1] : 1로 끝나는 i자리 이친수의 개수
long long dp[91][2]; // integer overflow 주의!!
int main(void) {
    cin >> N;
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 0;
    for (int i = 3; i <= N; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    cout << dp[N][0] + dp[N][1];
    return 0;
}

// https://www.acmicpc.net/problem/2193