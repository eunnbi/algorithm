#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[1001][1001];
int dp[1001][1001];

int main(void) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            board[i][j] = s[j - 1] - '0';
        }
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (board[i][j]) {
                dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
                res = max(res, dp[i][j]);
            }
        }
    }
    cout << res * res;
    return 0;
}

// https://www.acmicpc.net/problem/1915