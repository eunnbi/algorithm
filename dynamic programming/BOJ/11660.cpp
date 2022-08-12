#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[1026][1026];
int dp[1026][1026];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // 이차원 배열의 (1,1)부터 (i,j)까지의 누적합 구하기 (1-based indexing)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + board[i][j];
        }
    }

    int x1, y1, x2, y2;
    while (M--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}

// 2차원 배열 구간합
/*
1. 이차원 배열의 (1,1)부터 (i,j)까지의 누적합 구하기
   dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + board[i][j] (1-based indexing)
2. (i,j)부터 (x,y)까지의 부분합 구하기
   dp[x][y] - dp[x][j-1] - dp[i-1][y] + dp[i-1][j-1]
*/
// https://www.acmicpc.net/problem/11660