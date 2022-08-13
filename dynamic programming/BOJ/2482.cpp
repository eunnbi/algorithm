#include <bits/stdc++.h>
#define MOD 1000000003u
using namespace std;

int N, K;
int dp[1005][1005]; // dp[i][j] : i개의 색 중 j개의 색을 선택하는 경우의 수


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> K;
    for (int i = 1; i <= N; i++) dp[i][1] = i;
    for (int i = 3; i <= N; i++) {
        for (int j = 2; j <= K; j++) {
            if (j > i / 2) break;
            // i - 1개 중 j개 선택 + i번째 선택 X
            // i - 2개 중 j - 1개 선택 + i번째 선택 O
            dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
        }
    }
    cout << dp[N][K];
    return 0;
}

// https://www.acmicpc.net/problem/2482