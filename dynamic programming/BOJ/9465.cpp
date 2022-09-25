#include <bits/stdc++.h>
using namespace std;

int T, N;
int stickers[100001][2];
int dp[100001][2]; // dp[i][j] : i번째 열까지 점수의 최대값, 단 j행 i열의 스티커는 반드시 선택

// 가장 직전에 붙인 스티커가 i - 2열의 스티커인 경우 : max(dp[i - 2][0], dp[i - 2][1]) + stickers[i][j];
// 가장 직전에 붙인 스티커가 i - 1열의 스티커인 경우 : dp[i - 1][1 - j] + stickers[i][j];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                cin >> stickers[j][i];
                dp[j][i] = 0;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 2; j++) {
                int v = 0;
                if (i > 1) v = max(dp[i - 2][0], dp[i - 2][1]);
                if (i > 0) v = max(v, dp[i - 1][1 - j]);
                dp[i][j] = v + stickers[i][j];
            }
        }
        cout << max(dp[N - 1][0], dp[N - 1][1]) << '\n';
    }

    return 0;
}