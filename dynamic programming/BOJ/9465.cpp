#include <bits/stdc++.h>
using namespace std;

int T, N;
int dp[1002][1002]; // dp[i][j] : s1[0:i]와 s2[0:j]의 LCS

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        vector<vector<int>> arr(N, vector<int>(2)), dp(N, vector<int>(2)); // N by 2 vector 선언
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> arr[i][j];
             }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 2; j++) {
                int v = 0;
                if (i > 1) v = max(dp[i - 2][0], dp[i - 2][1]);
                if (i > 0) v = max(v, dp[i - 1][1 - j]);
                dp[i][j] = v + arr[i][j];
            }
        }
        cout << max(dp[N - 1][0], dp[N - 1][1]) << '\n';
    }

    return 0;
}

/*
dp[i][j] : i번째 열까지 점수의 최대값, 단 j행 i열의 스티커는 반드시 선택

가장 직전에 붙인 스티커가 i - 2열의 스티커인 경우 : max(dp[i - 2][0], dp[i - 2][1]) + arr[i][j];
가장 직전에 붙인 스티커가 i - 1열의 스티커인 경우 : dp[i - 1][1 - j] + arr[i][j];

마지막 열에 있는 스티커 중 어느 하나는 반드시 붙인게 최댓값이므로 max(dp[N - 1][0], dp[N - 1][1])을 계산하면 됨
*/
// https://www.acmicpc.net/problem/9465