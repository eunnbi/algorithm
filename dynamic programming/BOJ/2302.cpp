#include <bits/stdc++.h>
using namespace std;

int N, M;
int fix[41];
int dp[41]; // dp[i] : i개의 자리에 앉는 경우의 수


int main(void) {
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> fix[i];
    }
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; //  점화식!!
        // 좌석을 옮기지 않는 경우 : dp[i - 1]
        // 좌석을 옮기는 경우 : dp[i - 2]
    }
    
    int res = 1;
    for (int i = 0; i < M; i++) {
        if (i == 0) res *= dp[fix[i] - 1];
        else res *= dp[fix[i] - fix[i - 1] - 1];
    }
    if (fix[M - 1] != N) {
        res *= dp[N - fix[M - 1]];
    }
    cout << res;
    return 0;
}