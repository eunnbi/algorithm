#include <bits/stdc++.h>
using namespace std;

int T, W;
int tree[1002];
// dp[i][j][k] : i - 현재 시간, j - 이동횟수, k - 나무번호
int dp[1002][32][3];

int main(void) {
    cin >> T >> W;
    for (int i = 1; i <= T; i++) {
        cin >> tree[i];
    }

    for (int i = 1; i <= T; i++) {
        dp[i][0][1] = dp[i - 1][0][1] + (tree[i] == 1 ? 1 : 0); // 이동하지 않는 경우
        for (int j = 1; j <= W; j++) { // j번 이동
            if (i < j) break;
            if (tree[i] == 1) {
                dp[i][j][1] = max(dp[i - 1][j - 1][2], dp[i - 1][j][1]) + 1;
                dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]);
            }
            else {
                dp[i][j][1] = max(dp[i - 1][j - 1][2], dp[i - 1][j][1]);
                dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]) + 1;
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= W; i++) {
        res = max({ res, dp[T][i][1], dp[T][i][2] });
    }
    cout << res;
    return 0;
}

// https://www.acmicpc.net/problem/2240