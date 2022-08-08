#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int cnt, N;
int board[100001][3];
int dp[100001][3];
int dx[4] = { -1, 0, -1, -1 };
int dy[4] = { 0, -1, -1, 1 };


int main(void) {
    while (true) {
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> board[i][j];
            }
        }

        dp[0][0] = -1;
        dp[0][1] = board[0][1];
        dp[0][2] = board[0][1] + board[0][2];

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                int mn = MAX;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= 3) continue;
                    if (dp[nx][ny] == -1) continue;
                    if (mn > dp[nx][ny]) mn = dp[nx][ny];
                }
                dp[i][j] = mn + board[i][j];
            }
        }

        cout << cnt + 1 << ". ";
        cout << dp[N - 1][1] << '\n';
        cnt++;
    }
  
    return 0;
}