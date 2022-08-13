#include <bits/stdc++.h>
#define MOD 1000000003u
using namespace std;

int N, M;
int board[502][502];
int dp[502][502];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


// 재귀 bfs
int sol(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y]; // memoization
    if (x == N - 1 && y == M - 1) return 1; // 하나의 방법
    int& ret = dp[x][y];
    ret = 0;
    // 상하좌우로 움직이기
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (board[x][y] > board[nx][ny]) ret += sol(nx, ny); // 내리막길
    }
    return ret;
}



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    }
    cout << sol(0, 0);
    return 0;
}


// https://www.acmicpc.net/problem/1520