#include <bits/stdc++.h>
using namespace std;

int N;
int board[501][501];
int main(void) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> board[i][j];
            board[i][j] += max(board[i - 1][j], board[i - 1][j - 1]);
        }
    }
    int res = 0;
    for (int i = 1; i <= N; i++) {
        if (res < board[N][i]) res = board[N][i];
    }
    printf("%d", res);
    return 0;
}