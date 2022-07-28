#include <bits/stdc++.h>
using namespace std;

int N, L;
int board[101][101];
int vis[101][101];
int tmp[101][101];
int res;

void rotate() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = tmp[N - j - 1][i];
        }
    }
}

void sol() {
    for (int i = 0; i < N; i++) {
        bool isPossible = true;
        for (int j = 1; j < N; j++) {
            if (board[i][j - 1] == board[i][j]) continue;
            else if (abs(board[i][j - 1] - board[i][j]) == 1) {
                if (board[i][j - 1] < board[i][j]) {
                    int sum = 0;
                    int col = j - 1;
                    while (col >= 0 && board[i][col] == board[i][j - 1] && !vis[i][col]) {
                        sum++;
                        if (sum == L) {
                            for (int k = col; k <= j - 1; k++) {
                                vis[i][k] = 1;
                            }
                            break;
                        }
                        col--;
                    }
                    if (sum < L) {
                        isPossible = false;
                        break;
                    }
                }
                else {
                    int sum = 0;
                    int col = j;
                    while (col < N && board[i][col] == board[i][j] && !vis[i][col]) {
                        sum++;
                        if (sum == L) {
                            for (int k = j; k <= col; k++) {
                                vis[i][k] = 1;
                            }
                            break;

                        }
                        col++;
                    }
                    if (sum < L) {
                        isPossible = false;
                        break;
                    }

                } 
            }
            else {
                isPossible = false;
                break;
            }
        }
        if (isPossible) {
            //printf("%d\n", i);
            res++;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    sol();
    rotate();

    // vis 배열 초기화!!
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vis[i][j] = 0;
        }
    }
    sol();

    cout << res;
    return 0;
}

// https://www.acmicpc.net/problem/14890